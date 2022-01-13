#include "yul-gen.h"

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/DebugInfoSelection.h>
#include <liblangutil/Scanner.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/codegen/ir/IRGenerator.h>
#include <libsolidity/interface/CompilerStack.h>
#include <libsolutil/JSON.h>
#include <libyul/AsmJsonConverter.h>
#include <libyul/backends/evm/EVMDialect.h>
#include <solc/CommandLineInterface.h>

#include <boost/throw_exception.hpp>
#include <memory>

using namespace solidity::frontend;
using namespace solidity;
using namespace std;

namespace {
OptimiserSettings optimizerSettings() {
    string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
    auto compilerOptimizerSettings = OptimiserSettings::full();
    compilerOptimizerSettings.yulOptimiserSteps = yulOptimiserSteps;
    compilerOptimizerSettings.expectedExecutionsPerDeployment = 1;
    return compilerOptimizerSettings;
}

CommandLineInterface getCli(char const* sol_filepath) {
    constexpr int solc_argc = 2;
    char const* solc_argv[solc_argc] = {
        "--bin",
        sol_filepath,
    };

    istringstream sin;  // never used, but the CLI requires it
    ostringstream sout;
    CommandLineInterface cli{sin, sout, cerr};
    cli.parseArguments(solc_argc, solc_argv);
    cli.readInputFiles();
    return cli;
}
}  // namespace

std::string generateYul(std::string const& main_contract,
                        std::string const& filepath) {
    auto cli = getCli(filepath.c_str());
    auto fileReader = move(cli.fileReader());
    auto compiler = make_shared<CompilerStack>(fileReader.reader());
    compiler->setSources(fileReader.sourceUnits());
    size_t start = compiler->errors().size();

    try {
        if (!compiler->compile())
            throw std::runtime_error("Compilation failed");
    } catch (std::exception const& ex) {
        for (size_t i = start; i < compiler->errors().size(); i++) {
            auto err = compiler->errors()[i];
            if (err->errorSeverity(err->type()) !=
                solidity::langutil::Error::Severity::Error)
                continue;
            std::cout << "Compilation error : "
                      << compiler->errors()[i].get()->what() << std::endl;
        }
        throw;
    }

    auto sourceUnit = fileReader.cliPathToSourceUnitName({filepath});
    auto contractName = sourceUnit + ":" + main_contract;
    auto src = fileReader.sourceUnits().at(sourceUnit);
    solidity::langutil::CharStream charStream{src, sourceUnit};
    langutil::SingletonCharStreamProvider charStreamProvider{charStream};
    IRGenerator generator(
        cli.options().output.evmVersion, cli.options().output.revertStrings,
        optimizerSettings(), compiler->sourceIndices(),
        langutil::DebugInfoSelection::Default(), &charStreamProvider);

    string yulIR, yulIROptimized;
    auto otherYulSources = map<ContractDefinition const*, string_view const>();
    tie(yulIR, yulIROptimized) =
        generator.run(compiler->contractDefinition(contractName),
                      compiler->cborMetadata(contractName), otherYulSources);
    return yulIROptimized;
}

std::string generateYulJSON(std::string const& yul,
                            std::string const& filepath) {
    langutil::ErrorList errors;
    langutil::ErrorReporter errorReporter{errors};
    auto const& dialect =
        yul::EVMDialect::strictAssemblyForEVMObjects(langutil::EVMVersion{});
    yul::ObjectParser objectParser{errorReporter, dialect};

    langutil::CharStream ir = langutil::CharStream(yul, filepath);
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

    return jsonPrettyPrint(removeNullMembers(std::move(ret)));
}
