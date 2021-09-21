#include "StorageVariables.hpp"

StorageVars::StorageVars(std::string main_contract, const char* sol_filepath)
{
	m_contractDef	  = main_contract;
	m_storageVars_str = getStorageVars(sol_filepath);
}

solidity::frontend::CommandLineInterface StorageVars::getCli(char const* sol_filepath)
{
	std::string yulOptimiserSteps
		= solidity::frontend::OptimiserSettings::DefaultYulOptimiserSteps;
	std::erase(yulOptimiserSteps, 'i'); // remove FullInliner
	yulOptimiserSteps += " x";			// that flattens function calls: only one
										// function call per statement is allowed
	constexpr int solc_argc			   = 2;
	char const*	  solc_argv[solc_argc] = {
		  "--bin",
		  sol_filepath,
	  };

	std::istringstream						 sin; // never used, but the CLI requires it
	std::ostringstream						 sout;
	solidity::frontend::CommandLineInterface cli{sin, sout, std::cerr};
	if (not cli.parseArguments(solc_argc, solc_argv))
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc CLI failed to parse arguments"});
	if (not cli.readInputFiles())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to read input files"});

	return cli;
}

std::vector<std::string> StorageVars::getStorageVars(const char* sol_filepath)
{
	auto cli   = getCli(sol_filepath);
	auto paths = cli.options().input.paths;
	// For now we are only supporting single files;
	for (auto p: paths)
	{
		this->m_baseFileName = p;
	}

	solidity::frontend::FileReader m_fileReader = std::move(cli.fileReader());

	this->m_compiler
		= std::make_unique<solidity::frontend::CompilerStack>(m_fileReader.reader());
	solidity::frontend::CommandLineOptions m_options = cli.options();
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

	m_compiler->enableIRGeneration(m_options.compiler.outputs.ir
								   || m_options.compiler.outputs.irOptimized);
	m_compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);

	solidity::frontend::OptimiserSettings settings
		= m_options.optimizer.enabled ? solidity::frontend::OptimiserSettings::standard()
									  : solidity::frontend::OptimiserSettings::minimal();
	if (m_options.optimizer.expectedExecutionsPerDeployment.has_value())
		settings.expectedExecutionsPerDeployment
			= m_options.optimizer.expectedExecutionsPerDeployment.value();
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
	std::vector<std::string> storageVars;
	std::ostringstream		 contractDefinition;
	contractDefinition << m_baseFileName.string() << ":" << m_contractDef;
	auto stateVars = m_compiler->contractDefinition(contractDefinition.str()).stateVariables();
	m_storageVars_astNodes = stateVars;
	for (auto var: stateVars)
	{
		storageVars.emplace_back(var->name());
	}
	return storageVars;
}