#include "StorageVariables.hpp"

StorageVars::StorageVars(const char* sol_filepath)
{
    m_storageVars_str = getStorageVars(sol_filepath);
}

frontend::CommandLineInterface StorageVars::getCli(char const* sol_filepath)
{
	std::string yulOptimiserSteps = frontend::OptimiserSettings::DefaultYulOptimiserSteps;
	erase(yulOptimiserSteps, 'i'); // remove FullInliner
	yulOptimiserSteps += " x"; // that flattens function calls: only one
							   // function call per statement is allowed
	constexpr int solc_argc = 2;
	char const* solc_argv[solc_argc] = {
		"--bin",
		sol_filepath,
	};

	std::istringstream sin; // never used, but the CLI requires it
	std::ostringstream sout;
	frontend::CommandLineInterface cli{sin, sout, std::cerr};
	if (not cli.parseArguments(solc_argc, solc_argv))
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc CLI failed to parse arguments"});
	if (not cli.readInputFiles())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to read input files"});

	return cli;
}

vector<string> StorageVars::getStorageVars(const char* sol_filepath)
{
    auto cli = getCli(sol_filepath);
    solidity::frontend::FileReader m_fileReader = std::move(cli.fileReader());

	auto m_compiler = make_unique<CompilerStack>(m_fileReader.reader());
	CommandLineOptions m_options = cli.options();
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
	// TODO: Perhaps we should not compile unless requested

	m_compiler->enableIRGeneration(m_options.compiler.outputs.ir || m_options.compiler.outputs.irOptimized);
	m_compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);

	OptimiserSettings settings = m_options.optimizer.enabled ? OptimiserSettings::standard() : OptimiserSettings::minimal();
	if (m_options.optimizer.expectedExecutionsPerDeployment.has_value())
		settings.expectedExecutionsPerDeployment = m_options.optimizer.expectedExecutionsPerDeployment.value();
	if (m_options.optimizer.noOptimizeYul)
		settings.runYulOptimiser = false;

	if (m_options.optimizer.yulSteps.has_value())
		settings.yulOptimiserSteps = m_options.optimizer.yulSteps.value();
	settings.optimizeStackAllocation = settings.runYulOptimiser;
	m_compiler->setOptimiserSettings(settings);
	m_compiler->setSources(m_fileReader.sourceCodes());
	m_compiler->setParserErrorRecovery(m_options.input.errorRecovery);
	m_compiler->parse();
	m_compiler->analyze();
	// bool successful = m_compiler->compile(m_options.output.stopAfter);
    vector<string> storageVars;    
	auto stateVars = m_compiler->contractDefinition("ERC20.sol:WARP").stateVariables();
	m_storageVars_astNodes = stateVars;
    for (auto var : stateVars)
    {
        storageVars.emplace_back(var->name());
    }
    return storageVars;
}