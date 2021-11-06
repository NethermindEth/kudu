#include "WarpVisitor.hpp"

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
#include <regex>

#include "yul_prepass/YulCleaner.hpp"
#include "yul_prepass/YulVisitor.hpp"

inline bool fileExists(const std::string& name) {
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0);
}

void generateYulAST(std::string yul, std::string filePath) {
  langutil::CharStream ir = langutil::CharStream(yul, filePath);
  std::variant<phaser::Program, langutil::ErrorList> maybeProgram =
      phaser::Program::load(ir);

  if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram)) {
    langutil::SingletonCharStreamProvider streamProvider{ir};
    langutil::SourceReferenceFormatter{std::cerr, streamProvider, true, false}
        .printErrorInformation(*errorList);
    std::cerr << std::endl;
  }
  auto program = std::get<phaser::Program>(maybeProgram);
  std::cout << program.toJson() << std::endl;
}

void deleteFile(std::string filePath) {
  if (!std::remove(filePath.c_str()))
    return;
  else
    std::cout << "file " << filePath << " not found.\n";
}

std::string joinSrcSplit(std::vector<std::string> srcSplit) {
  std::string newSrc;
  std::for_each(srcSplit.begin(), srcSplit.end(),
                [&newSrc](std::string line) { newSrc += line + "\n"; });
  return newSrc;
}

void replaceIdentifierName(std::string& srcString, std::string identifier,
                           std::string newIdentifier) {
  std::ostringstream regexStr;
  regexStr << "(\\b)" << identifier << "\\b";
  std::regex r(regexStr.str());
  std::string result = std::regex_replace(srcString, r, newIdentifier);
  srcString = result;
}

SourceData::SourceData(std::string main_contract, std::string src,
                       std::string filepath, bool print_ir) {
  m_src = src;
  m_print_ir = print_ir;
  m_srcSplit = splitStr(m_src);
  this->removeComments();
  m_filepath = filepath;
  m_mainContract = main_contract;
  m_modifiedSolFilepath =
      std::string(filepath.begin(), filepath.end() - 4) + "_marked.sol";
  this->writeModifiedSolidity();
  this->prepareSoliditySource(m_modifiedSolFilepath.c_str());
}

int getEndOfMultiLineComment(std::vector<std::string> lines, int start) {
  for (size_t i = start; i < lines.size(); i++) {
    boost::trim(lines[i]);
    if (boost::starts_with(lines[i], "*/")) return i;
  }
  throw std::runtime_error("Failed to find end of multi line comment.");
  return -1;
}

void SourceData::removeComments() {
  std::vector<std::string> newSplit;
  int jump = 1;
  for (size_t i = 0; i < m_srcSplit.size(); i += jump) {
    if (i > m_srcSplit.size()) break;
    auto lineCopy = m_srcSplit[i];
    boost::trim(lineCopy);
    if (boost::starts_with(lineCopy, "//")) {
      jump = 1;
    } else if (boost::starts_with(lineCopy, "/*")) {
      auto end = getEndOfMultiLineComment(m_srcSplit, i);
      jump = end + 1 - (i);
      if (i + jump > m_srcSplit.size()) break;
    } else {
      jump = 1;
      newSplit.emplace_back(m_srcSplit[i]);
    }
  }
  std::string newSrc;
  std::for_each(newSplit.begin(), newSplit.end(),
                [&newSrc](std::string line) { newSrc += line + "\n"; });
  this->m_srcSplit = newSplit;
  this->m_src = newSrc;
}

bool SourceData::hasDynamicArgs(std::string params) {
  return params.find("calldata") != std::string::npos ||
         params.find("memory") != std::string::npos;
}

bool SourceData::visitNode(ASTNode const& node) {
  return ASTConstVisitor::visitNode(node);
}

bool SourceData::isPublic(Visibility _visibility) {
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

void SourceData::writeModifiedSolidity() {
  std::string solStr;
  for (auto line : m_srcSplit) solStr += line + "\n";

  std::fstream solFile;
  solFile.open(m_modifiedSolFilepath, std::ios::out | std::ios::trunc);
  solFile << solStr;
  solFile.close();
  m_src = solStr;
}

CommandLineInterface SourceData::getCli(char const* sol_filepath) {
  std::string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
  std::erase(yulOptimiserSteps, 'i');  // remove FullInliner
  std::erase(yulOptimiserSteps, 'F');
  std::erase(yulOptimiserSteps, 'v');
  yulOptimiserSteps += "x";  // that flattens function calls: only one
                             // function call per statement is allowed
  constexpr int solc_argc = 2;
  char const* solc_argv[solc_argc] = {
      "--bin",
      sol_filepath,
  };

  std::istringstream sin;  // never used, but the CLI requires it
  std::ostringstream sout;
  CommandLineInterface cli{sin, sout, std::cerr};
  if (not cli.parseArguments(solc_argc, solc_argv))
    BOOST_THROW_EXCEPTION(
        std::runtime_error{"solc CLI failed to parse arguments"});
  if (not cli.readInputFiles())
    BOOST_THROW_EXCEPTION(
        std::runtime_error{"solc failed to read input files"});

  return cli;
}
bool SourceData::visit(Identifier const& _node) {
  // std::cout << _node.name() << std::endl;
  return visitNode(_node);
}
bool SourceData::visit(VariableDeclaration const& _node) {
  if (m_currentPass == PassType::ConstructorPass) {
    if (_node.isStateVariable()) {
      if (_node.mutability() == VariableDeclaration::Mutability::Immutable)
        throw std::runtime_error(
            "Warp does not support immutable storage variables yet. ");
    }
  }
  return visitNode(_node);
}
bool SourceData::visit(FunctionDefinition const& _node) {
  if (m_currentPass == PassType::FunctionDefinitionPass) {
    std::string sig;
    if (not _node.isImplemented()) {
      sig = std::string(m_srcOriginal.begin() + _node.location().start,
                        m_srcOriginal.begin() + _node.location().end);
    } else {
      sig = std::string(
          m_srcOriginal.begin() + _node.location().start,
          m_srcOriginal.begin() + _node.body().location().start + 1);
    }
    if (_node.isPartOfExternalInterface()) {
      int paramsStart = _node.parameterList().location().start + 1;
      int paramsEnd = _node.parameterList().location().end - 1;
      auto params = std::string(m_srcOriginal.begin() + paramsStart,
                                m_srcOriginal.begin() + paramsEnd);
      if (not contains_warp(m_storageVars_str, _node.name()) and
          hasDynamicArgs(params)) {
        auto markedName = _node.name() + "_dynArgs";
        auto markedSig = "function " + markedName +
                         std::string(sig.begin() + sig.find('('), sig.end()) +
                         "\n";
        boost::replace_all(m_src, sig, markedSig);
        m_dynArgFunctions.names.emplace_back(_node.name());
        std::vector<Type const*> params;
        for (auto param : _node.parameters()) {
          params.emplace_back(param->type());
        }
        m_dynArgFunctions.parameters.emplace_back(params);
        m_dynArgFunctions.selectors.emplace_back(_node.externalIdentifierHex());
        m_srcSplit = splitStr(m_src);
      }
    }
  }
  return visitNode(_node);
}

bool SourceData::visit(FunctionCall const& _node) {
  if (m_currentPass == PassType::FunctionCallPass) {
    auto funcDef =
        resolveFunctionCall(m_compiler->contractDefinition(
                                m_modifiedSolFilepath + ":" + m_mainContract),
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
        auto line =
            std::string(m_srcOriginal.begin() + _node.location().start,
                        m_srcOriginal.begin() + _node.location().end + 1);

        auto call = std::string(m_srcOriginal.begin() + _node.location().start,
                                m_srcOriginal.begin() + _node.location().end);
        auto callMarked = call;
        auto dynName = funcDef->name() + "_dynArgs";
        replaceIdentifierName(callMarked, funcDef->name(), dynName);
        boost::replace_all(m_src, call, callMarked);
        m_srcSplit = splitStr(m_src);
      }
    }
  }
  return visitNode(_node);
}

FunctionDefinition const* SourceData::insideWhichFunction(
    langutil::SourceLocation const& location) {
  FunctionDefinition const* dummy;
  for (auto func : m_definedFunctions) {
    if (func->location().contains(location)) {
      return func;
    }
  }
  throw std::runtime_error(
      "failed to find which function the given SourceLocation falls in");
  return dummy;
}

bool SourceData::checkTypeEqaulity(std::vector<Type const*> const& t1,
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

FunctionDefinition const* SourceData::resolveFunctionCall(
    const ContractDefinition& c, FunctionCall const& f) {
  return ASTNode::resolveFunctionCall(f, &c);
}

void SourceData::getInheritedConstructorCalls(
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
      auto fullyQualifiedName = m_modifiedSolFilepath + ":" + modDeclr->name();
      if (modDeclr and contains_warp(m_contractNames, fullyQualifiedName)) {
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
                    dynamic_cast<Literal const&>(*expr).annotation().type;
                switch (type->category()) {
                  case Type::Category::RationalNumber:
                  case Type::Category::Bool:
                  case Type::Category::Address: {
                    solidity::u256 literal = type->literalValue(
                        &dynamic_cast<Literal const&>(*expr));
                    callArguments.emplace_back(boost::to_string(literal));
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
            m_compiler->contractDefinition(modDeclr->name()).constructor();
        if (constructorDef) {
          auto params = constructorDef->parameters();
          auto paramsStart = constructorDef->parameterList().location().start;
          auto paramsEnd = constructorDef->parameterList().location().end;
          auto paramsStr = std::string(m_srcOriginal.begin() + paramsStart,
                                       m_srcOriginal.begin() + paramsEnd);
          auto bodyStart = constructorDef->body().location().start;
          auto bodyEnd = constructorDef->body().location().end;
          auto body = std::string(m_srcOriginal.begin() + bodyStart,
                                  m_srcOriginal.begin() + bodyEnd);
          if (body != "{}") {
            auto bodyOnly = std::string(m_srcOriginal.begin() + bodyStart + 1,
                                        m_srcOriginal.begin() + bodyEnd - 1);
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
          return getInheritedConstructorCalls(constructorDef->modifiers());
        }
      }
    }
  }
}

void SourceData::generateWarpConstructor() {
  FunctionDefinition const* constructor =
      m_compiler->contractDefinition(m_modifiedContractName).constructor();
  if (not constructor) {
    m_willGenerateConstructor = false;
    return;
  }
  m_willGenerateConstructor = true;
  auto constructorStr =
      std::string(m_srcOriginal.begin() + constructor->location().start,
                  m_srcOriginal.begin() + constructor->location().end);
  auto paramsStart = constructor->parameterList().location().start;
  auto paramsEnd = constructor->parameterList().location().end;
  auto params = std::string(m_srcOriginal.begin() + paramsStart,
                            m_srcOriginal.begin() + paramsEnd);
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
  auto body = std::string(m_srcOriginal.begin() + bodyStart,
                          m_srcOriginal.begin() + bodyEnd);
  m_warpConstructor += params + " public {\n";
  if (body != "{}") {
    auto bodyOnly = std::string(m_srcOriginal.begin() + bodyStart + 1,
                                m_srcOriginal.begin() + bodyEnd - 1);
    m_warpConstructor += bodyOnly;
  }
  getInheritedConstructorCalls(constructor->modifiers());
  m_warpConstructor += "}\n";
  std::vector<std::string> newSrcSplit;
  bool inMainContract = false;
  std::string check = "contract " + m_mainContract;
  for (size_t i = 0; i < m_srcSplit.size(); ++i) {
    if (m_srcSplit[i].find(check) != std::string::npos) {
      inMainContract = true;
    }
    if (m_srcSplit[i].find(" constructor(") != std::string::npos and
        inMainContract) {
      newSrcSplit.emplace_back(m_warpConstructor);
    }
    newSrcSplit.emplace_back(m_srcSplit[i]);
  }
  m_srcSplit = newSrcSplit;
}

void SourceData::setCompilerOptions(std::shared_ptr<CompilerStack> compiler) {
  if (m_options.metadata.literalSources)
    compiler->useMetadataLiteralSources(true);
  compiler->setMetadataHash(m_options.metadata.hash);
  if (m_options.modelChecker.initialize)
    compiler->setModelCheckerSettings(m_options.modelChecker.settings);
  compiler->setRemappings(m_options.input.remappings);
  compiler->setLibraries(m_options.linker.libraries);
  compiler->setViaIR(m_options.output.experimentalViaIR);
  compiler->setEVMVersion(m_options.output.evmVersion);
  compiler->setRevertStringBehaviour(m_options.output.revertStrings);
  compiler->enableIRGeneration(m_options.compiler.outputs.ir ||
                               m_options.compiler.outputs.irOptimized);
  compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);

  this->setYulOptimizerSettings();

  this->m_compiler->setOptimiserSettings(m_compilerOptimizerSettings);
  this->m_compiler->setSources(m_fileReader.sourceCodes());
  this->m_compiler->setParserErrorRecovery(m_options.input.errorRecovery);
}

void SourceData::setYulOptimizerSettings() {
  std::string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
  std::erase(yulOptimiserSteps, 'i');  // remove FullInliner
  std::erase(yulOptimiserSteps, 'F');
  std::erase(yulOptimiserSteps, 'v');
  yulOptimiserSteps += "x";  // that flattens function calls: only one

  this->m_compilerOptimizerSettings = OptimiserSettings::full();
  this->m_compilerOptimizerSettings.yulOptimiserSteps = yulOptimiserSteps;
  this->m_compilerOptimizerSettings.expectedExecutionsPerDeployment = 1;
}

void SourceData::dynFuncArgsPass(const char* solFilepath) {
  auto cli = getCli(solFilepath);
  auto paths = cli.options().input.paths;

  this->m_fileReader = std::move(cli.fileReader());
  this->m_compiler = std::make_shared<CompilerStack>(m_fileReader.reader());
  this->m_options = cli.options();
  this->setCompilerOptions(m_compiler);
  this->m_compiler->parse();
  this->m_compiler->analyze();
  this->m_compiler->compile();

  this->refreshStateAfterModification();

  this->m_srcOriginal = m_src;
  this->m_currentPass = PassType::FunctionDefinitionPass;
  this->m_compiler->ast(solFilepath).accept(*this);
  this->m_src = joinSrcSplit(this->m_srcSplit);

  this->m_currentPass = PassType::FunctionCallPass;
  this->m_compiler->ast(m_modifiedSolFilepath).accept(*this);

  this->m_src = joinSrcSplit(this->m_srcSplit);
  this->writeModifiedSolidity();
}

void SourceData::constrcutorPass(const char* solFilepath) {
  auto cli = getCli(solFilepath);
  auto paths = cli.options().input.paths;

  this->m_fileReader = std::move(cli.fileReader());
  this->m_compiler = std::make_shared<CompilerStack>(m_fileReader.reader());
  this->m_options = cli.options();
  this->setCompilerOptions(m_compiler);
  this->m_compiler->parse();
  this->m_compiler->analyze();
  this->m_compiler->compile();
  this->refreshStateAfterModification();
  this->m_currentPass = PassType::ConstructorPass;
  this->m_srcOriginal = m_src;
  this->m_compiler->ast(m_modifiedSolFilepath).accept(*this);
  this->generateWarpConstructor();
  this->m_src = joinSrcSplit(this->m_srcSplit);
  this->writeModifiedSolidity();
  this->refreshStateAfterModification();
}

void SourceData::refreshStateAfterModification() {
  this->m_compiler->reset(true);
  auto newCli = getCli(m_modifiedSolFilepath.c_str());
  auto paths = newCli.options().input.paths;

  this->m_fileReader = std::move(newCli.fileReader());
  this->m_options = newCli.options();
  this->setCompilerOptions(m_compiler);
  this->m_compiler->parse();
  this->m_compiler->analyze();
  this->m_compiler->compile();
  this->m_definedFunctions.clear();
  this->m_storageVars_str.clear();
  this->m_srcOriginal = m_src;
  m_contractNames = m_compiler->contractNames();
  m_interfaceNames.clear();
  m_storageVars_str.clear();
  m_interfaces.clear();
  m_definedFunctions = std::vector<FunctionDefinition const*>();
  for (auto name : m_contractNames) {
    auto unQualifiedName =
        std::string(name.begin() + name.find(":") + 1, name.end());
    m_interfaceNames.emplace_back(unQualifiedName);
    std::vector<std::string> definedFuncs;
    for (auto var :
         this->m_compiler->contractDefinition(name).stateVariables()) {
      this->m_storageVars_str.emplace_back(var->name());
    }
    for (auto func :
         this->m_compiler->contractDefinition(name).definedFunctions()) {
      this->m_definedFunctions.emplace_back(func);
      definedFuncs.emplace_back(func->name());
    }
    if (this->m_compiler->contractDefinition(name).isInterface()) {
      m_interfaces[unQualifiedName] = definedFuncs;
    }
  }
}

std::string SourceData::getSaferYul() {
  auto newCli = getCli(m_modifiedSolFilepath.c_str());
  auto paths = newCli.options().input.paths;
  this->m_fileReader = std::move(newCli.fileReader());
  this->m_options = newCli.options();
  IRGenerator generator(
      newCli.options().output.evmVersion, newCli.options().output.revertStrings,
      m_compilerOptimizerSettings, m_compiler->sourceIndices());

  std::string yulIR, yulIROptimized;
  auto otherYulSources =
      std::map<ContractDefinition const*, std::string_view const>();

  tie(yulIR, yulIROptimized) = generator.run(
      m_compiler->contractDefinition(m_modifiedContractName),
      m_compiler->cborMetadata(m_modifiedContractName), otherYulSources);

  return yulIROptimized;
}

void SourceData::prepareSoliditySource(const char* sol_filepath) {
  std::ostringstream modifiedContractName;
  modifiedContractName << m_modifiedSolFilepath << ":" << m_mainContract;
  m_modifiedContractName = modifiedContractName.str();
  // Removing this optimization for now, as we are adding all functions
  // to fun_ENTRY_POINT for warped->warped contract calls
  // this->dynFuncArgsPass(sol_filepath);
  this->constrcutorPass(sol_filepath);
  auto newCli = getCli(m_modifiedSolFilepath.c_str());
  auto paths = newCli.options().input.paths;
  this->m_fileReader = std::move(newCli.fileReader());
  this->m_options = newCli.options();

  IRGenerator generator(
      newCli.options().output.evmVersion, newCli.options().output.revertStrings,
      m_compilerOptimizerSettings, m_compiler->sourceIndices());

  std::string yulIR, yulIROptimized;
  auto otherYulSources =
      std::map<ContractDefinition const*, std::string_view const>();

  tie(yulIR, yulIROptimized) = generator.run(
      m_compiler->contractDefinition(m_modifiedContractName),
      m_compiler->cborMetadata(m_modifiedContractName), otherYulSources);
  auto prepass = YulCleaner(m_src, m_mainContract,
                            m_modifiedSolFilepath.c_str(), m_storageVars_str);

  auto yul = prepass.cleanYul(yulIROptimized, m_mainContract);
  if (m_print_ir) {
    std::cout << yul << std::endl;
    return;
  }

  // =============== Generate Yul JSON AST ===============
  langutil::CharStream ir = langutil::CharStream(yul, m_modifiedSolFilepath);
  std::variant<phaser::Program, langutil::ErrorList> maybeProgram =
      phaser::Program::load(ir);

  if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram)) {
    langutil::SingletonCharStreamProvider streamProvider{ir};
    langutil::SourceReferenceFormatter{std::cerr, streamProvider, true, false}
        .printErrorInformation(*errorList);
    std::cerr << std::endl;
  }
  auto program = std::get<phaser::Program>(maybeProgram);
  auto yulVisitor =
      YulVisitor(yul, m_warpConstructorSelector, m_warpConstructorName);
  yulVisitor(program.ast());
  generateYulAST(yulVisitor.m_src, "YUL_PASS");

  if (fileExists("YUL_PASS")) deleteFile("YUL_PASS");
}
