#include "SolidityModifierState.hpp"

#include <libsolidity/interface/OptimiserSettings.h>

SolidityModifierState& SolidityModifierState::initSrc(std::string _src) {
    src = _src;
    srcOriginal = _src;
    srcSplit = splitStr(_src);
    return *this;
};

SolidityModifierState& SolidityModifierState::initCLI() {
    std::string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
    std::erase(yulOptimiserSteps, 'i');  // remove FullInliner
    std::erase(yulOptimiserSteps, 'F');
    std::erase(yulOptimiserSteps, 'v');
    yulOptimiserSteps += "x";  // that flattens function calls: only one
    // function call per statement is allowed
    constexpr int solc_argc = 2;
    char const* solc_argv[solc_argc] = {
        "--bin",
        this->modifiedSolFilePath.c_str(),
    };

    std::istringstream sin;  // never used, but the CLI requires it
    std::ostringstream sout;

    this->cli = std::make_unique<CommandLineInterface>(
        CommandLineInterface(sin, sout, std::cerr));

    if (not cli->parseArguments(solc_argc, solc_argv))
        BOOST_THROW_EXCEPTION(
            std::runtime_error{"solc CLI failed to parse arguments"});
    if (not cli->readInputFiles())
        BOOST_THROW_EXCEPTION(
            std::runtime_error{"solc failed to read input files"});
    if (not cli->processInput())
        BOOST_THROW_EXCEPTION(
            std::runtime_error{"solc failed to read input files"});

    return *this;
}

SolidityModifierState& SolidityModifierState::initCompiler() {
    FileReader reader = cli->fileReader();
    this->compiler = std::make_shared<CompilerStack>(reader.reader());
    return *this;
}

SolidityModifierState& SolidityModifierState::refresh() {
    compiler->reset(true);
    FileReader fileReader = cli->fileReader();
    initCLI().initCompiler().setCompilerOptions();
    compiler->parse();
    compiler->analyze();
    compiler->compile();
    contractNames = compiler->contractNames();
    interfaceNames.clear();
    storageVars_str.clear();
    interfaces.clear();
    definedFunctions = std::vector<FunctionDefinition const*>();
    for (auto name : contractNames) {
        auto unQualifiedName =
            std::string(name.begin() + name.find(":") + 1, name.end());
        interfaceNames.emplace_back(unQualifiedName);
        std::vector<std::string> definedFuncs;
        for (auto var : compiler->contractDefinition(name).stateVariables()) {
            storageVars_str.emplace_back(var->name());
        }
        for (auto func :
             compiler->contractDefinition(name).definedFunctions()) {
            definedFunctions.emplace_back(func);
            definedFuncs.emplace_back(func->name());
        }
        if (compiler->contractDefinition(name).isInterface()) {
            interfaces[unQualifiedName] = definedFuncs;
        }
    }
    return *this;
}

SolidityModifierState& SolidityModifierState::setCompilerOptions() {
    if (cli->options().metadata.literalSources)
        compiler->useMetadataLiteralSources(true);
    compiler->setMetadataHash(cli->options().metadata.hash);
    if (cli->options().modelChecker.initialize)
        compiler->setModelCheckerSettings(cli->options().modelChecker.settings);
    compiler->setRemappings(cli->options().input.remappings);
    compiler->setLibraries(cli->options().linker.libraries);
    compiler->setViaIR(cli->options().output.experimentalViaIR);
    compiler->setEVMVersion(cli->options().output.evmVersion);
    compiler->setRevertStringBehaviour(cli->options().output.revertStrings);
    compiler->enableIRGeneration(cli->options().compiler.outputs.ir ||
                                 cli->options().compiler.outputs.irOptimized);
    compiler->enableEvmBytecodeGeneration(
        cli->options().compiler.estimateGas ||
        cli->options().compiler.outputs.asm_ ||
        cli->options().compiler.outputs.asmJson ||
        cli->options().compiler.outputs.opcodes ||
        cli->options().compiler.outputs.binary ||
        cli->options().compiler.outputs.binaryRuntime ||
        (cli->options().compiler.combinedJsonRequests &&
         (cli->options().compiler.combinedJsonRequests->binary ||
          cli->options().compiler.combinedJsonRequests->binaryRuntime ||
          cli->options().compiler.combinedJsonRequests->opcodes ||
          cli->options().compiler.combinedJsonRequests->asm_ ||
          cli->options().compiler.combinedJsonRequests->generatedSources ||
          cli->options()
              .compiler.combinedJsonRequests->generatedSourcesRuntime ||
          cli->options().compiler.combinedJsonRequests->srcMap ||
          cli->options().compiler.combinedJsonRequests->srcMapRuntime ||
          cli->options().compiler.combinedJsonRequests->funDebug ||
          cli->options().compiler.combinedJsonRequests->funDebugRuntime)));
    compiler->enableEwasmGeneration(cli->options().compiler.outputs.ewasm);

    auto yulSteps = yulOptimizerSteps();

    this->compiler->setOptimiserSettings(optimizerSettings);
    this->compiler->setSources(cli->fileReader().sourceCodes());
    this->compiler->setParserErrorRecovery(cli->options().input.errorRecovery);
    return *this;
}

std::string SolidityModifierState::yulOptimizerSteps() {
    std::string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
    std::erase(yulOptimiserSteps, 'i');  // remove FullInliner
    std::erase(yulOptimiserSteps, 'F');
    std::erase(yulOptimiserSteps, 'v');
    yulOptimiserSteps += "x";  // that flattens function calls: only one
    this->optimizerSettings = OptimiserSettings::full();
    optimizerSettings.yulOptimiserSteps = yulOptimiserSteps;
    optimizerSettings.expectedExecutionsPerDeployment = 1;
    return yulOptimiserSteps;
}
