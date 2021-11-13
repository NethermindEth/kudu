#include "WarpVisitor.hpp"

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/Exceptions.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/codegen/ir/IRGenerator.h>
#include <libsolutil/IndentedWriter.h>
#include <libsolutil/Keccak256.h>
#include <libyul/AsmJsonConverter.h>
#include <tools/yulPhaser/Program.h>

#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <cstdio>

#include "libwarp/common/library.hpp"
#include "libwarp/yul_prepass/YulCleaner.hpp"
#include "libwarp/yul_prepass/YulVisitor.hpp"

WarpVisitor::WarpVisitor(const string& main_contract, const string& src,
                         const string& filepath, bool print_ir) {
    m_src = removeComments(removeEmptyLines(src));
    m_srcOriginal = src;
    m_print_ir = print_ir;
    m_srcSplit = splitStr(m_src);
    m_filepath = filepath;
    m_mainSourceUnit =
        m_fileReader.cliPathToSourceUnitName(boost::filesystem::path(filepath));
    m_mainContract = main_contract;
    m_modifiedSolFilepath =
        string(m_filepath.begin(), m_filepath.end() - 4) + "_marked.sol";
    m_modifiedSourceUnit = m_fileReader.cliPathToSourceUnitName(
        boost::filesystem::path(m_modifiedSolFilepath));
    m_modifiedContractName = m_modifiedSourceUnit + ":" + m_mainContract;
    m_contractName = filepath + ":" + m_mainContract;
    newCompiler();
    consolidateImports();
    constrcutorPass();
}

int getEndOfMultiLineComment(vector<string> lines, int start) {
    for (size_t i = start; i < lines.size(); i++) {
        boost::trim(lines[i]);
        if (boost::starts_with(lines[i], "*/")) return i;
    }
    throw runtime_error("Failed to find end of multi line comment.");
    return -1;
}

string WarpVisitor::removeComments(string src) {
    auto srcSplit = splitStr(src);
    vector<string> newSplit;
    int jump = 1;
    for (size_t i = 0; i < srcSplit.size(); i += jump) {
        if (i > srcSplit.size()) break;
        auto lineCopy = srcSplit[i];
        boost::trim(lineCopy);
        if (boost::starts_with(lineCopy, "//")) {
            jump = 1;
        } else if (boost::starts_with(lineCopy, "/*")) {
            if (lineCopy.find("*/") == string::npos) {
                auto end = getEndOfMultiLineComment(srcSplit, i);
                jump = end + 1 - (i);
                if (i + jump > srcSplit.size()) break;
            } else {
                jump = 1;
            }
        } else {
            jump = 1;
            newSplit.emplace_back(srcSplit[i]);
        }
    }
    string newSrc;
    for_each(newSplit.begin(), newSplit.end(),
             [&newSrc](const string& line) { newSrc += line + "\n"; });
    return newSrc;
}

bool WarpVisitor::visitNode(ASTNode const& node) {
    return ASTConstVisitor::visitNode(node);
}

void WarpVisitor::writeModifiedSolidity() {
    writeFile(m_modifiedSolFilepath, m_src);
}

CommandLineInterface WarpVisitor::getCli(char const* sol_filepath) {
    string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
    erase(yulOptimiserSteps, 'i');  // remove FullInliner
    constexpr int solc_argc = 2;
    char const* solc_argv[solc_argc] = {
        "--bin",
        sol_filepath,
    };

    istringstream sin;  // never used, but the CLI requires it
    ostringstream sout;
    CommandLineInterface cli{sin, sout, cerr};
    if (not cli.parseArguments(solc_argc, solc_argv))
        BOOST_THROW_EXCEPTION(
            runtime_error{"solc CLI failed to parse arguments"});
    if (not cli.readInputFiles())
        BOOST_THROW_EXCEPTION(runtime_error{"solc failed to read input files"});

    return cli;
}

bool WarpVisitor::visit(VariableDeclaration const& _node) {
    if (m_currentPass == PassType::ConstructorPass) {
        if (_node.isStateVariable()) {
            if (_node.mutability() ==
                VariableDeclaration::Mutability::Immutable)
                throw runtime_error(
                    "Warp does not support immutable storage variables yet. ");
        }
    }
    return visitNode(_node);
}

bool WarpVisitor::visit(ImportDirective const& _node) {
    string absolutePath = *_node.annotation().absolutePath;
    string declrPath = _node.path();
    if (contains_warp(m_orderedImportPaths, absolutePath)) {
        return visitNode(_node);
    } else {
        m_orderedImportPaths.emplace_back(absolutePath);
        return visitNode(_node);
    }
}

void WarpVisitor::getInheritedConstructorCalls(
    vec<ASTPointer<ModifierInvocation>> const& modifiers) {
    if (modifiers.size() == 0)
        return;
    else {
        for (auto mod : modifiers) {
            vec<ASTPointer<Expression>> modifierCallArgs;
            if (mod->arguments()) {
                modifierCallArgs = *mod->arguments();
            }
            auto modDeclr = mod->name().annotation().referencedDeclaration;
            auto fullyQualifiedName =
                m_modifiedSourceUnit + ":" + modDeclr->name();
            if (modDeclr and
                contains_warp(m_contractNames, fullyQualifiedName)) {
                vec<string> callArguments;
                for_each(
                    modifierCallArgs.begin(), modifierCallArgs.end(),
                    [&callArguments](ASTPointer<Expression> expr) {
                        try {
                            string identifier =
                                dynamic_cast<Identifier const&>(*expr).name();
                            callArguments.emplace_back(identifier);
                        } catch (const bad_cast& e) {
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
                    m_compiler->contractDefinition(modDeclr->name())
                        .constructor();
                if (constructorDef) {
                    auto params = constructorDef->parameters();
                    auto paramsStart =
                        constructorDef->parameterList().location().start;
                    auto paramsEnd =
                        constructorDef->parameterList().location().end;
                    auto paramsStr = string(m_srcOriginal.begin() + paramsStart,
                                            m_srcOriginal.begin() + paramsEnd);
                    auto bodyStart = constructorDef->body().location().start;
                    auto bodyEnd = constructorDef->body().location().end;
                    auto body = string(m_srcOriginal.begin() + bodyStart,
                                       m_srcOriginal.begin() + bodyEnd);
                    if (body != "{}") {
                        auto bodyOnly =
                            string(m_srcOriginal.begin() + bodyStart + 1,
                                   m_srcOriginal.begin() + bodyEnd - 1);
                        bool eq = params.size() == callArguments.size();
                        solAssert(eq,
                                  "WarpVisitor.cpp:195 -> parameter.size() != "
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
        m_compiler->contractDefinition(m_modifiedContractName).constructor();
    if (!constructor) {
        return;
    }
    auto paramsStart = constructor->parameterList().location().start;
    auto paramsEnd = constructor->parameterList().location().end;
    auto params = string(m_srcOriginal.begin() + paramsStart,
                         m_srcOriginal.begin() + paramsEnd);
    if (params.find(" calldata ") != string::npos or
        params.find(" memory ") != string::npos) {
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
    auto body = string(m_srcOriginal.begin() + bodyStart,
                       m_srcOriginal.begin() + bodyEnd);
    m_warpConstructor += params + " public {\n";
    if (body != "{}") {
        auto bodyOnly = string(m_srcOriginal.begin() + bodyStart + 1,
                               m_srcOriginal.begin() + bodyEnd - 1);
        m_warpConstructor += bodyOnly;
    }
    getInheritedConstructorCalls(constructor->modifiers());
    m_warpConstructor += "}\n";
    vec<string> newSrcSplit;
    bool inMainContract = false;
    string check = "contract " + m_mainContract;
    for (size_t i = 0; i < m_srcSplit.size(); ++i) {
        if (m_srcSplit[i].find(check) != string::npos) {
            inMainContract = true;
        }
        if (m_srcSplit[i].find(" constructor(") != string::npos and
            inMainContract) {
            newSrcSplit.emplace_back(m_warpConstructor);
        }
        newSrcSplit.emplace_back(m_srcSplit[i]);
    }
    m_srcSplit = newSrcSplit;
}

void WarpVisitor::setCompilerOptions() {
    if (m_options.metadata.literalSources)
        m_compiler->useMetadataLiteralSources(true);
    m_compiler->setMetadataHash(m_options.metadata.hash);
    if (m_options.modelChecker.initialize)
        m_compiler->setModelCheckerSettings(m_options.modelChecker.settings);
    m_compiler->setRemappings(m_options.input.remappings);
    m_compiler->setLibraries(m_options.linker.libraries);
    m_compiler->setViaIR(m_options.output.experimentalViaIR);
    m_compiler->setEVMVersion(m_options.output.evmVersion);
    m_compiler->setRevertStringBehaviour(m_options.output.revertStrings);
    m_compiler->enableIRGeneration(m_options.compiler.outputs.ir ||
                                   m_options.compiler.outputs.irOptimized);
    m_compiler->enableEvmBytecodeGeneration(
        m_options.compiler.estimateGas || m_options.compiler.outputs.asm_ ||
        m_options.compiler.outputs.asmJson ||
        m_options.compiler.outputs.opcodes ||
        m_options.compiler.outputs.binary ||
        m_options.compiler.outputs.binaryRuntime ||
        (m_options.compiler.combinedJsonRequests &&
         (m_options.compiler.combinedJsonRequests->binary ||
          m_options.compiler.combinedJsonRequests->binaryRuntime ||
          m_options.compiler.combinedJsonRequests->opcodes ||
          m_options.compiler.combinedJsonRequests->asm_ ||
          m_options.compiler.combinedJsonRequests->generatedSources ||
          m_options.compiler.combinedJsonRequests->generatedSourcesRuntime ||
          m_options.compiler.combinedJsonRequests->srcMap ||
          m_options.compiler.combinedJsonRequests->srcMapRuntime ||
          m_options.compiler.combinedJsonRequests->funDebug ||
          m_options.compiler.combinedJsonRequests->funDebugRuntime)));
    m_compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);
    m_compiler->setOptimiserSettings(optimizerSettings());
    m_compiler->setSources(m_fileReader.sourceCodes());
    m_compiler->setParserErrorRecovery(m_options.input.errorRecovery);
}

OptimiserSettings WarpVisitor::optimizerSettings() {
    string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
    erase(yulOptimiserSteps, 'i');  // remove FullInliner
    auto compilerOptimizerSettings = OptimiserSettings::full();
    compilerOptimizerSettings.yulOptimiserSteps = yulOptimiserSteps;
    compilerOptimizerSettings.expectedExecutionsPerDeployment = 1;
    return compilerOptimizerSettings;
}

void WarpVisitor::constrcutorPass() {
    m_currentPass = PassType::ConstructorPass;
    m_srcOriginal = m_src;
    m_compiler->ast(m_modifiedSourceUnit).accept(*this);
    generateWarpConstructor();
    m_src = joinSrcSplit(m_srcSplit);
    writeModifiedSolidity();
    refreshCompilerState(m_modifiedSolFilepath);
}

void WarpVisitor::newCompiler() {
    auto cli = getCli(m_filepath.c_str());
    m_fileReader = move(cli.fileReader());
    m_compiler = make_shared<CompilerStack>(m_fileReader.reader());
    m_options = cli.options();
    setCompilerOptions();
    size_t start = this->m_compiler->errors().size();

    try {
        if (!this->m_compiler->compile())
            throw std::runtime_error("Compilation failed");
    } catch (std::exception const& ex) {
        for (size_t i = start; i < this->m_compiler->errors().size(); i++) {
            auto err = this->m_compiler->errors()[i];
            if (err->errorSeverity(err->type()) !=
                solidity::langutil::Error::Severity::Error)
                continue;
            std::cout << "Compilation error : "
                      << this->m_compiler->errors()[i].get()->what()
                      << std::endl;
        }
        throw;
    }
}

void WarpVisitor::refreshCompilerState(string filepath) {
    m_compiler->reset(true);
    auto newCli = getCli(filepath.c_str());
    m_fileReader = move(newCli.fileReader());
    m_options = newCli.options();
    setCompilerOptions();
    size_t start = this->m_compiler->errors().size();

    try {
        if (!this->m_compiler->compile())
            throw std::runtime_error("Compilation failed");
    } catch (std::exception const& ex) {
        for (size_t i = start; i < this->m_compiler->errors().size(); i++) {
            auto err = this->m_compiler->errors()[i];
            if (err->errorSeverity(err->type()) !=
                solidity::langutil::Error::Severity::Error)
                continue;
            std::cout << "Compilation error : "
                      << this->m_compiler->errors()[i].get()->what()
                      << std::endl;
        }
        throw;
    }
    m_contractNames = m_compiler->contractNames();
}

WarpVisitor& WarpVisitor::generateYulAST() {
    langutil::CharStream ir =
        langutil::CharStream(m_yulIR, m_modifiedSourceUnit);
    variant<phaser::Program, langutil::ErrorList> maybeProgram =
        phaser::Program::load(ir);

    if (auto* errorList = get_if<langutil::ErrorList>(&maybeProgram)) {
        langutil::SingletonCharStreamProvider streamProvider{ir};
        langutil::SourceReferenceFormatter{cerr, streamProvider, true, false}
            .printErrorInformation(*errorList);
        cerr << endl;
    }
    auto program = get<phaser::Program>(maybeProgram);
    m_yul_JSON_AST = program.toJson();
    return *this;
}

WarpVisitor& WarpVisitor::yulPrepass() {
    refreshCompilerState(m_modifiedSolFilepath);
    auto newCli = getCli(m_modifiedSolFilepath.c_str());
    m_fileReader = move(newCli.fileReader());
    m_options = newCli.options();
    solidity::langutil::CharStream charStream{m_src, m_modifiedSourceUnit};
    langutil::SingletonCharStreamProvider charStreamProvider{charStream};
    IRGenerator generator(newCli.options().output.evmVersion,
                          newCli.options().output.revertStrings,
                          optimizerSettings(), m_compiler->sourceIndices(),
                          &charStreamProvider);

    string yulIR, yulIROptimized;
    auto otherYulSources = map<ContractDefinition const*, string_view const>();
    tie(yulIR, yulIROptimized) = generator.run(
        m_compiler->contractDefinition(m_modifiedContractName),
        m_compiler->cborMetadata(m_modifiedContractName), otherYulSources);
    auto prepass = YulCleaner();

    m_yulIR = prepass.cleanYul(yulIROptimized, m_mainContract);
    return *this;
}

WarpVisitor& WarpVisitor::yulPass() {
    langutil::CharStream ir =
        langutil::CharStream(m_yulIR, m_modifiedSourceUnit);
    variant<phaser::Program, langutil::ErrorList> maybeProgram =
        phaser::Program::load(ir);

    if (auto* errorList = get_if<langutil::ErrorList>(&maybeProgram)) {
        langutil::SingletonCharStreamProvider streamProvider{ir};
        langutil::SourceReferenceFormatter{cerr, streamProvider, true, false}
            .printErrorInformation(*errorList);
        cerr << endl;
    }
    auto program = get<phaser::Program>(maybeProgram);
    auto yulVisitor =
        YulVisitor(m_yulIR, m_warpConstructorSelector, m_warpConstructorName);
    yulVisitor(program.ast());
    m_yulIR = yulVisitor.m_src;
    if (m_print_ir) cout << "========YUL IR========\n" + m_yulIR << endl;
    return *this;
}

void WarpVisitor::referencedSourceUnits(const SourceUnit& currSourceUnit) {
    string path = *currSourceUnit.annotation().path;
    for (ImportDirective const* importDirective :
         ASTNode::filteredNodes<ImportDirective>(currSourceUnit.nodes())) {
        auto const& sourceUnit = importDirective->annotation().sourceUnit;
        string absPath = *importDirective->annotation().absolutePath;
        if (!contains_warp(m_importedFiles, absPath)) {
            m_importedFiles.emplace_back(absPath);
            referencedSourceUnits(*sourceUnit);
            m_importStr += cleanImportedFile(absPath);
        }
    }
}

string WarpVisitor::removeImportDirectives(string src) {
    string newSrc;
    stringstream ss(src);
    string line;
    while (getline(ss, line)) {
        if (line.find("import \'") != string::npos) {
            continue;
        }
        newSrc += line + "\n";
    }
    return newSrc;
}

string WarpVisitor::cleanImportedFile(const string& path) {
    string src = slurpFile(path);
    auto vecStr = splitStr(removeComments(removeEmptyLines(src)));
    for (auto it = vecStr.begin(); it != vecStr.end();) {
        if (it->find("import \'") != string::npos or
            it->find("pragma ") != string::npos) {
            it = vecStr.erase(it);
        } else {
            ++it;
        }
    }
    return joinSrcSplit(vecStr);
}

void WarpVisitor::consolidateImports() {
    m_compiler->ast(m_mainSourceUnit).accept(*this);
    referencedSourceUnits(m_compiler->ast(m_mainSourceUnit));
    m_importStr = removeEmptyLines(m_importStr);
    m_src = removeImportDirectives(m_src);
    m_src = m_importStr + m_src;
    m_srcSplit = splitStr(m_src);
    writeModifiedSolidity();
    refreshCompilerState(m_modifiedSolFilepath);
}
