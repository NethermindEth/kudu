#include "WarpVisitor.hpp"

#include <json/value.h>
#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/Exceptions.h>
#include <liblangutil/Scanner.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/codegen/ir/IRGenerator.h>
#include <libsolutil/IndentedWriter.h>
#include <libsolutil/JSON.h>
#include <libsolutil/Keccak256.h>
#include <libyul/AsmJsonConverter.h>
#include <libyul/backends/evm/EVMDialect.h>
#include <tools/yulPhaser/Program.h>

#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/throw_exception.hpp>
#include <cstdio>
#include <stdexcept>

#include "libwarp/common/library.hpp"


WarpVisitor::WarpVisitor(const string& main_contract, const string& src,
                         const string& filepath, bool print_ir) {
    m_src = removeComments(removeEmptyLines(src));
    m_print_ir = print_ir;
    m_filepath = filepath;
    m_mainSourceUnit =
        m_fileReader.cliPathToSourceUnitName(boost::filesystem::path(filepath));
    m_modifiedSolFilepath =
        string(m_filepath.begin(), m_filepath.end() - 4) + "_marked.sol";
    m_modifiedSourceUnit = m_fileReader.cliPathToSourceUnitName(
        boost::filesystem::path(m_modifiedSolFilepath));
    m_modifiedContractName = m_modifiedSourceUnit + ":" + main_contract;
    newCompiler();
    consolidateImports();
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
    if (_node.type()->category() == Type::Category::Function) 
        BOOST_THROW_EXCEPTION(runtime_error{"Warp does not support Functions as data yet"});
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
    auto compilerOptimizerSettings = OptimiserSettings::full();
    compilerOptimizerSettings.yulOptimiserSteps = yulOptimiserSteps;
    compilerOptimizerSettings.expectedExecutionsPerDeployment = 1;
    return compilerOptimizerSettings;
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
    if (m_print_ir) cout << "========YUL IR========\n" + m_yulIR << endl;

    langutil::ErrorList errors;
    langutil::ErrorReporter errorReporter{errors};
    auto const& dialect =
        yul::EVMDialect::strictAssemblyForEVMObjects(langutil::EVMVersion{});
    yul::ObjectParser objectParser{errorReporter, dialect};

    langutil::CharStream ir =
        langutil::CharStream(m_yulIR, m_modifiedSourceUnit);
    auto scanner = make_shared<langutil::Scanner>(ir);
    auto object = objectParser.parse(scanner, false);

    if (!object or !errors.empty()) {
        langutil::SingletonCharStreamProvider streamProvider{ir};
        langutil::SourceReferenceFormatter{cerr, streamProvider, true, false}
            .printErrorInformation(errors);
        cerr << endl;
        BOOST_THROW_EXCEPTION(runtime_error{"Parsing yul code failed"});
    }

    auto deploymentCode = object->code;

    std::shared_ptr<yul::Block> runtimeCode{};
    std::string runtimeObjectName = object->name.str() + "_deployed";
    for (auto&& subObject : object->subObjects)
        if (subObject && subObject->name.str() == runtimeObjectName)
            if (auto* runtimeObject =
                    dynamic_cast<yul::Object*>(subObject.get())) {
                runtimeCode = runtimeObject->code;
                break;
            }

    if (!runtimeCode) {
        BOOST_THROW_EXCEPTION(
            runtime_error{"Runtime code not found in the yul object"});
    }

    yul::AsmJsonConverter jsonConverter{{}};
    Json::Value ret{Json::objectValue};
    ret["deploymentCode"] = jsonConverter(*deploymentCode);
    ret["runtimeCode"] = jsonConverter(*runtimeCode);

    m_yul_JSON_AST = jsonPrettyPrint(removeNullMembers(std::move(ret)));
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
    m_yulIR = yulIROptimized;
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
        if (line.find("import \'") != string::npos or
            line.find("import \"") != string::npos) {
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
            it->find("import \"") != string::npos or
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
    writeModifiedSolidity();
    refreshCompilerState(m_modifiedSolFilepath);
}
