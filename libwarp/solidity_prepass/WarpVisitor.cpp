#include "WarpVisitor.hpp"

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/EVMVersion.h>
#include <liblangutil/Exceptions.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/codegen/ir/IRGenerator.h>
#include <libsolidity/interface/DebugSettings.h>
#include <libsolutil/IndentedWriter.h>
#include <libsolutil/Keccak256.h>
#include <libyul/AsmJsonConverter.h>
#include <tools/yulPhaser/Program.h>

#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <cstdio>
#include <regex>

#include "libwarp/yul_prepass/YulCleaner.hpp"
#include "libwarp/yul_prepass/YulVisitor.hpp"

void replaceIdentifierName(std::string& srcString, std::string identifier,
                           std::string newIdentifier) {
    std::ostringstream regexStr;
    regexStr << "(\\b)" << identifier << "\\b";
    std::regex r(regexStr.str());
    std::string result = std::regex_replace(srcString, r, newIdentifier);
    srcString = result;
}

WarpVisitor::WarpVisitor(std::string main_contract, std::string src,
                         std::string filepath, bool print_ir) {
    std::string modifiedSolFilepath =
        std::string(filepath.begin(), filepath.end() - 4) + "_marked.sol";
    this->m_solModifier.src(src)
        .modifiedSolFilePath(modifiedSolFilepath)
        .consolidateImports()
        .removeComments()
        .writeModifiedSolidity();
    m_print_ir = print_ir;
    m_mainContract = main_contract;
}

bool WarpVisitor::hasDynamicArgs(std::string params) {
    return params.find("calldata") != std::string::npos ||
           params.find("memory") != std::string::npos;
}

bool WarpVisitor::visitNode(ASTNode const& node) {
    return ASTConstVisitor::visitNode(node);
}

bool WarpVisitor::isPublic(Visibility _visibility) {
    switch (_visibility) {
        case Visibility::Public:
        case Visibility::External: {
            return true;
            break;
        }
        default: {
            return false;
            break;
        }
    }
}

bool WarpVisitor::visit(Identifier const& _node) { return visitNode(_node); }

bool WarpVisitor::visit(VariableDeclaration const& _node) {
    if (m_currentPass == PassType::ConstructorPass) {
        if (_node.isStateVariable()) {
            if (_node.mutability() ==
                VariableDeclaration::Mutability::Immutable)
                throw std::runtime_error(
                    "Warp does not support immutable storage variables yet. ");
        }
    }
    return visitNode(_node);
}
bool WarpVisitor::visit(FunctionDefinition const& _node) {
    if (m_currentPass == PassType::FunctionDefinitionPass) {
        std::string sig;
        if (not _node.isImplemented()) {
            sig = std::string(
                m_solState->srcOriginal.begin() + _node.location().start,
                m_solState->srcOriginal.begin() + _node.location().end);
        } else {
            sig = std::string(
                m_solState->srcOriginal.begin() + _node.location().start,
                m_solState->srcOriginal.begin() +
                    _node.body().location().start + 1);
        }
        if (_node.isPartOfExternalInterface()) {
            int paramsStart = _node.parameterList().location().start + 1;
            int paramsEnd = _node.parameterList().location().end - 1;
            auto params =
                std::string(m_solState->srcOriginal.begin() + paramsStart,
                            m_solState->srcOriginal.begin() + paramsEnd);
            if (not contains_warp(m_solState->storageVars_str, _node.name()) and
                hasDynamicArgs(params)) {
                auto markedName = _node.name() + "_dynArgs";
                auto markedSig =
                    "function " + markedName +
                    std::string(sig.begin() + sig.find('('), sig.end()) + "\n";
                boost::replace_all(m_solState->src, sig, markedSig);
                m_dynArgFunctions.names.emplace_back(_node.name());
                std::vector<Type const*> params;
                for (auto param : _node.parameters()) {
                    params.emplace_back(param->type());
                }
                m_dynArgFunctions.parameters.emplace_back(params);
                m_dynArgFunctions.selectors.emplace_back(
                    _node.externalIdentifierHex());
                m_solState->srcSplit = splitStr(m_solState->src);
            }
        }
    }
    return visitNode(_node);
}

bool WarpVisitor::visit(FunctionCall const& _node) {
    if (m_currentPass == PassType::FunctionCallPass) {
        auto funcDef = resolveFunctionCall(
            m_solState->compiler->contractDefinition(
                m_solModifier.m_modifiedSolFilePath + ":" + m_mainContract),
            _node);
        if (funcDef != nullptr) {
            auto selector = funcDef->externalIdentifierHex();
            int found = 0;
            std::for_each(m_dynArgFunctions.selectors.begin(),
                          m_dynArgFunctions.selectors.end(),
                          [&found, &selector](const std::string& id) {
                              found += int((id == selector));
                          });
            if (found == 1) {
                auto line = std::string(
                    m_solState->srcOriginal.begin() + _node.location().start,
                    m_solState->srcOriginal.begin() + _node.location().end + 1);

                auto call = std::string(
                    m_solState->srcOriginal.begin() + _node.location().start,
                    m_solState->srcOriginal.begin() + _node.location().end);
                auto callMarked = call;
                auto dynName = funcDef->name() + "_dynArgs";
                replaceIdentifierName(callMarked, funcDef->name(), dynName);
                boost::replace_all(m_solState->src, call, callMarked);
                m_solState->srcSplit = splitStr(m_solState->src);
            }
        }
    }
    return visitNode(_node);
}

FunctionDefinition const* WarpVisitor::insideWhichFunction(
    langutil::SourceLocation const& location) {
    FunctionDefinition const* dummy;
    for (auto func : m_solState->definedFunctions) {
        if (func->location().contains(location)) {
            return func;
        }
    }
    throw std::runtime_error(
        "failed to find which function the given SourceLocation falls in");
    return dummy;
}

bool WarpVisitor::checkTypeEqaulity(std::vector<Type const*> const& t1,
                                    std::vector<Type const*> t2) {
    if (t1.size() != t2.size())
        return false;
    else {
        for (size_t i = 0; i < t1.size(); ++i) {
            if (*t1[i] != *t2[i]) return false;
        }
        return true;
    }
}

FunctionDefinition const* WarpVisitor::resolveFunctionCall(
    const ContractDefinition& c, FunctionCall const& f) {
    return ASTNode::resolveFunctionCall(f, &c);
}

void WarpVisitor::getInheritedConstructorCalls(
    std::vector<ASTPointer<ModifierInvocation>> const& modifierCalls) {
    if (modifierCalls.size() == 0)
        return;
    else {
        for (auto mod : modifierCalls) {
            std::vector<ASTPointer<Expression>> modifierCallArgs;
            if (mod->arguments()) {
                modifierCallArgs = *mod->arguments();
            }
            auto modDeclr = mod->name().annotation().referencedDeclaration;
            auto fullyQualifiedName =
                m_solModifier.m_modifiedSolFilePath + ":" + modDeclr->name();
            if (modDeclr and
                contains_warp(m_solState->contractNames, fullyQualifiedName)) {
                std::vector<std::string> callArguments;
                std::for_each(
                    modifierCallArgs.begin(), modifierCallArgs.end(),
                    [&callArguments](ASTPointer<Expression> expr) {
                        try {
                            std::string identifier =
                                dynamic_cast<Identifier const&>(*expr).name();
                            callArguments.emplace_back(identifier);
                        } catch (const std::bad_cast& e) {
                            Type const* type =
                                dynamic_cast<Literal const&>(*expr)
                                    .annotation()
                                    .type;
                            switch (type->category()) {
                                case Type::Category::RationalNumber:
                                case Type::Category::Bool:
                                case Type::Category::Address: {
                                    solidity::u256 literal = type->literalValue(
                                        &dynamic_cast<Literal const&>(*expr));
                                    callArguments.emplace_back(
                                        boost::to_string(literal));
                                    break;
                                }
                                default:
                                    solUnimplemented(
                                        "Only integer and boolean literals "
                                        "implemented for now.");
                            }
                        }
                    });
                auto constructorDef =
                    m_solState->compiler->contractDefinition(modDeclr->name())
                        .constructor();
                if (constructorDef) {
                    auto params = constructorDef->parameters();
                    auto paramsStart =
                        constructorDef->parameterList().location().start;
                    auto paramsEnd =
                        constructorDef->parameterList().location().end;
                    auto paramsStr = std::string(
                        m_solState->srcOriginal.begin() + paramsStart,
                        m_solState->srcOriginal.begin() + paramsEnd);
                    auto bodyStart = constructorDef->body().location().start;
                    auto bodyEnd = constructorDef->body().location().end;
                    auto body =
                        std::string(m_solState->srcOriginal.begin() + bodyStart,
                                    m_solState->srcOriginal.begin() + bodyEnd);
                    if (body != "{}") {
                        auto bodyOnly = std::string(
                            m_solState->srcOriginal.begin() + bodyStart + 1,
                            m_solState->srcOriginal.begin() + bodyEnd - 1);
                        bool eq = params.size() == callArguments.size();
                        solAssert(eq,
                                  "WarpVisitor.cpp:376 -> parameter.size() != "
                                  "callArguments.size().");
                        for (size_t i = 0; i < params.size(); ++i) {
                            replaceIdentifierName(bodyOnly, params[i]->name(),
                                                  callArguments[i]);
                        }
                        m_warpConstructor += bodyOnly;
                    }
                    return getInheritedConstructorCalls(
                        constructorDef->modifiers());
                }
            }
        }
    }
}

void WarpVisitor::generateWarpConstructor() {
    FunctionDefinition const* constructor =
        m_solState->compiler->contractDefinition(m_modifiedContractName)
            .constructor();
    if (not constructor) {
        m_willGenerateConstructor = false;
        return;
    }
    m_willGenerateConstructor = true;
    auto constructorStr = std::string(
        m_solState->srcOriginal.begin() + constructor->location().start,
        m_solState->srcOriginal.begin() + constructor->location().end);
    auto paramsStart = constructor->parameterList().location().start;
    auto paramsEnd = constructor->parameterList().location().end;
    auto params = std::string(m_solState->srcOriginal.begin() + paramsStart,
                              m_solState->srcOriginal.begin() + paramsEnd);
    if (params.find(" calldata ") != std::string::npos or
        params.find(" memory ") != std::string::npos) {
        m_warpConstructor = "    function __warp_ctorHelper_DynArgs";
        m_warpConstructorName = "fun_warp_ctorHelper_DynArgs";
        m_warpConstructorSig = "__warp_ctorHelper_DynArgs(";
    } else {
        m_warpConstructor = "    function __warp_constructor";
        m_warpConstructorName = "fun_warp_constructor";
        m_warpConstructorSig = "__warp_constructor(";
    }
    for (size_t i = 0; i < constructor->parameters().size(); i++) {
        auto param = constructor->parameters()[i];
        if (i == constructor->parameters().size() - 1)
            m_warpConstructorSig +=
                param->type()->signatureInExternalFunction(false) + ")";
        else
            m_warpConstructorSig +=
                param->type()->signatureInExternalFunction(false) + ",";
    }
    boost::replace_all(m_warpConstructorSig, "uint,", "uint256,");
    m_warpConstructorSelector =
        "0x" + solidity::util::FixedHash<4>(
                   solidity::util::keccak256(m_warpConstructorSig))
                   .hex();
    auto bodyStart = constructor->body().location().start;
    auto bodyEnd = constructor->body().location().end;
    auto body = std::string(m_solState->srcOriginal.begin() + bodyStart,
                            m_solState->srcOriginal.begin() + bodyEnd);
    m_warpConstructor += params + " public {\n";
    if (body != "{}") {
        auto bodyOnly =
            std::string(m_solState->srcOriginal.begin() + bodyStart + 1,
                        m_solState->srcOriginal.begin() + bodyEnd - 1);
        m_warpConstructor += bodyOnly;
    }
    getInheritedConstructorCalls(constructor->modifiers());
    m_warpConstructor += "}\n";
    std::vector<std::string> newSrcSplit;
    bool inMainContract = false;
    std::string check = "contract " + m_mainContract;
    for (size_t i = 0; i < m_solState->srcSplit.size(); ++i) {
        if (m_solState->srcSplit[i].find(check) != std::string::npos) {
            inMainContract = true;
        }
        if (m_solState->srcSplit[i].find(" constructor(") !=
                std::string::npos and
            inMainContract) {
            newSrcSplit.emplace_back(m_warpConstructor);
        }
        newSrcSplit.emplace_back(m_solState->srcSplit[i]);
    }
    m_solState->srcSplit = newSrcSplit;
}

WarpVisitor& WarpVisitor::constrcutorPass(const char* solFilepath) {
    m_currentPass = PassType::ConstructorPass;
    m_solState->compiler->ast(m_solState->modifiedSolFilePath).accept(*this);
    generateWarpConstructor();
    m_solState->refresh();
    return *this;
}

WarpVisitor& WarpVisitor::yul() {
    solidity::langutil::CharStream charStream{m_solState->src,
                                              m_solState->modifiedSolFilePath};
    langutil::SingletonCharStreamProvider charStreamProvider{charStream};
    IRGenerator generator(langutil::EVMVersion::london(),
                          RevertStrings::Default, m_solState->optimizerSettings,
                          m_solState->compiler->sourceIndices(),
                          &charStreamProvider);

    std::string yulIR, yulIROptimized;
    auto otherYulSources =
        std::map<ContractDefinition const*, std::string_view const>();
    tie(yulIR, yulIROptimized) = generator.run(
        m_solState->compiler->contractDefinition(m_modifiedContractName),
        m_solState->compiler->cborMetadata(m_modifiedContractName),
        otherYulSources);
    m_yulIR = yulIROptimized;
    return *this;
}

WarpVisitor& WarpVisitor::yulPrepass() {
    auto prepass = YulCleaner(m_solState->src, m_mainContract,
                              m_solState->modifiedSolFilePath.c_str(),
                              m_solState->storageVars_str);
    m_yulIR = prepass.cleanYul(m_yulIR, m_mainContract);
    return *this;
}

WarpVisitor& WarpVisitor::generateYulIR() {
    langutil::CharStream ir =
        langutil::CharStream(m_yulIR, m_solState->modifiedSolFilePath);
    std::variant<phaser::Program, langutil::ErrorList> maybeProgram =
        phaser::Program::load(ir);

    if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram)) {
        langutil::SingletonCharStreamProvider streamProvider{ir};
        langutil::SourceReferenceFormatter{std::cerr, streamProvider, true,
                                           false}
            .printErrorInformation(*errorList);
        std::cerr << std::endl;
    }
    auto program = std::get<phaser::Program>(maybeProgram);
    auto yulVisitor =
        YulVisitor(m_yulIR, m_warpConstructorSelector, m_warpConstructorName);
    yulVisitor(program.ast());
    m_yulIR = yulVisitor.m_src;
    if (m_print_ir)
        std::cout << "========YUL IR========\n" + m_yulIR << std::endl;
    return *this;
}

WarpVisitor& WarpVisitor::generateYulAST() {
    langutil::CharStream ir =
        langutil::CharStream(m_yulIR, m_solState->modifiedSolFilePath);
    std::variant<phaser::Program, langutil::ErrorList> maybeProgram =
        phaser::Program::load(ir);

    if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram)) {
        langutil::SingletonCharStreamProvider streamProvider{ir};
        langutil::SourceReferenceFormatter{std::cerr, streamProvider, true,
                                           false}
            .printErrorInformation(*errorList);
        std::cerr << std::endl;
    }
    auto program = std::get<phaser::Program>(maybeProgram);
    m_yul_JSON_AST = program.toJson();
    if (fileExists("YUL_PASS")) deleteFile("YUL_PASS");
    return *this;
}
