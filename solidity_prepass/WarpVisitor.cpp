#include "WarpVisitor.hpp"
#include <boost/algorithm/string.hpp>
#include <libsolutil/IndentedWriter.h>
#include <regex>

SourceData::SourceData(std::string main_contract, std::string src, std::string filepath)
{
	m_src				  = src;
	m_filepath			  = filepath;
	m_mainContract		  = main_contract;
	m_modifiedSolFilepath = std::string(filepath.begin(), filepath.end() - 4) + "_marked.sol";
	// setSourceData(filepath.c_str());
	m_publicFunctions.hashes = this->getPublicFunchashes(filepath);
}

void SourceData::removeDuplicates()
{
	std::sort(m_publicFunctions.sigs.begin(), m_publicFunctions.sigs.end());
	m_publicFunctions.sigs.erase(
		std::unique(m_publicFunctions.sigs.begin(), m_publicFunctions.sigs.end()),
		m_publicFunctions.sigs.end());
}

bool SourceData::contains_warp(std::vector<std::string> vec, std::string search)
{
	auto it = std::find(vec.begin(), vec.end(), search);
	return it != vec.end();
}


std::string SourceData::exec(std::string cmdStr)
{
	const char*								 cmd = cmdStr.c_str();
	std::array<char, 4096>					 buffer;
	std::string								 result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe)
	{
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	{
		result += buffer.data();
	}
	return result;
}


std::vector<std::string> SourceData::getPublicFunchashes(const std::string& contract_path)
{
	std::ostringstream		 cmd;
	std::vector<std::string> hashes;
	std::vector<std::string> hashNames;
	cmd << "solc --combined-json hashes " << contract_path;
	json res	   = json::parse(exec(cmd.str()));
	auto contracts = res["contracts"];
	for (auto contract: contracts)
	{
		for (auto hash: contract["hashes"].items())
		{
			auto		key	 = hash.key();
			auto		end	 = key.find('(');
			std::string name = std::string(key.begin(), key.begin() + end);
			if (not contains_warp(this->m_storageVars, name))
			{
				hashes.emplace_back(hash.value());
				hashNames.emplace_back(name);
			}
		}
	}
	std::sort(hashes.begin(), hashes.end());
	hashes.erase(std::unique(hashes.begin(), hashes.end()), hashes.end());

	std::sort(hashNames.begin(), hashNames.end());
	hashNames.erase(std::unique(hashNames.begin(), hashNames.end()), hashNames.end());
	m_hashNames = hashNames;
	return hashes;
}

bool SourceData::hasDynamicArgs(std::string params)
{
	return params.find("calldata") != std::string::npos
		   || params.find("memory") != std::string::npos;
}

bool SourceData::visitNode(solidity::frontend::ASTNode const& node)
{
	return solidity::frontend::ASTConstVisitor::visitNode(node);
}

int SourceData::getSigEnd(int start)
{
	for (auto i = start; i < m_srcSplit.size(); i++)
	{
		if (m_srcSplit[i].find("{") != std::string::npos)
			return i;
	}
	std::runtime_error("Failed to find end of signature");
}

void SourceData::makeFunNamesUnique()
{
	auto count = 0;
	for (auto i = 0; i < m_srcSplit.size(); i++)
	{
		if (m_srcSplit[i].find("function") != std::string::npos)
		{
		}
	}
}

void SourceData::compressSigs()
{
	std::vector<std::string> newSplit;
	auto					 jump  = 1;
	auto					 count = 0;
	for (auto i = 0; i < m_srcSplit.size(); i += jump)
	{
		if (m_srcSplit[i].find("function") != std::string::npos)
		{
			if (m_srcSplit[i].find("{") != std::string::npos)
			{
				newSplit.emplace_back(m_srcSplit[i]);
			}
			else
			{
				auto end = getSigEnd(i);
				jump	 = end + 1 - (i);
				std::string sig;
				std::for_each(m_srcSplit.begin() + i,
							  m_srcSplit.begin() + end + 1,
							  [&sig](std::string v) { sig += v + "\n"; });
				newSplit.emplace_back(sig);
			}
		}
		else
		{
			newSplit.emplace_back(m_srcSplit[i]);
			jump = 1;
		}
	}
	m_srcSplit = newSplit;
}

[[nodiscard]] bool SourceData::visit(solidity::frontend::FunctionDefinition const& _node)
{
	m_functionNames.push_back(_node.name());
	if (_node.isConstructor())
		return visitNode(_node);
	try
	{
		if (isPublic(_node.visibility()))
		{
			int			paramsStart	  = _node.parameterList().location().start + 1;
			int			paramsEnd	  = _node.parameterList().location().end - 1;
			int			functionStart = _node.location().start;
			int			functionEnd	  = _node.location().end;
			int			bodyStart	  = _node.body().location().start;
			int			bodyEnd		  = _node.body().location().end;
			auto		body = std::string(m_src.begin() + bodyStart + 1, m_src.begin() + bodyEnd);
			auto		funcLocation = std::make_pair(functionStart, functionEnd);
			std::string params		 = std::string(
				  m_src.begin() + paramsStart, m_src.begin() + paramsEnd);
			if (not contains_warp(m_storageVars, _node.name()) and hasDynamicArgs(params))
			{
				auto sig = "    "
						   + std::string(m_src.begin() + _node.location().start,
										 m_src.begin() + _node.body().location().start + 1);
				auto match		= std::find_if(m_srcSplit.begin(),
										   m_srcSplit.end(),
										   [&sig](std::string v)
										   { return v.find(sig) != std::string::npos; });
				int	 index		= std::distance(m_srcSplit.begin(), match);
				auto markedName = _node.name() + "_dynArgs";
				auto markedSig	= "    function " + markedName
								 + std::string(sig.begin() + sig.find('('), sig.end());
				m_srcSplit[index] = markedSig;
			}
		}
		return visitNode(_node);
	}
	catch (boost::wrapexcept<solidity::langutil::InternalCompilerError> e)
	{
		return visitNode(_node);
	}
}

[[nodiscard]] bool SourceData::isPublic(solidity::frontend::Visibility _visibility)
{
	switch (_visibility)
	{
	case solidity::frontend::Visibility::Public:
	case solidity::frontend::Visibility::External:
	{
		return true;
		break;
	}
	default:
	{
		return false;
		break;
	}
	}
}

void SourceData::writeModifiedSolidity()
{
	std::string solStr;
	for (auto line: m_srcSplit)
		solStr += line + "\n";

	std::fstream solFile;
	solFile.open(m_modifiedSolFilepath, std::ios::out | std::ios::trunc);
	solFile << solStr;
	solFile.close();
	m_src = solStr;
}

solidity::frontend::CommandLineInterface SourceData::getCli(char const* sol_filepath)
{
	std::string yulOptimiserSteps = solidity::frontend::OptimiserSettings::DefaultYulOptimiserSteps;
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

bool SourceData::visit(solidity::frontend::FunctionCall const& _node) 
{
	using namespace solidity::frontend;
	std::vector<ASTPointer<Expression const>> arguments = _node.arguments();
	Type const* firstArgType = arguments[0]->annotation().type;
	for (auto arg : arguments)
		std::cout << arg->annotation().type->canonicalName() << std::endl;
	return true;
}

void SourceData::test(const solidity::frontend::ContractDefinition& c,  solidity::frontend::FunctionCall const& f)
{
	auto def = solidity::frontend::ASTNode::resolveFunctionCall(f, &c);
	// resolveFunctionCall(FunctionCall const& _functionCall, ContractDefinition const* _mostDerivedContract);
	std::cout << def->name() << std::endl;
}

void SourceData::setSourceData(const char* sol_filepath)
{
	auto cli   = getCli(sol_filepath);
	auto paths = cli.options().input.paths;
	// For now we are only supporting single files;
	for (auto p: paths)
	{
		this->m_baseFileName = p.filename();
	}

	solidity::frontend::FileReader m_fileReader = std::move(cli.fileReader());

	this->m_compiler = make_unique<solidity::frontend::CompilerStack>(m_fileReader.reader());
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
	m_compiler->enableIRGeneration(m_options.compiler.outputs.ir
								   || m_options.compiler.outputs.irOptimized);
	m_compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);

	solidity::frontend::OptimiserSettings settings = m_options.optimizer.enabled
														 ? solidity::frontend::OptimiserSettings::
															 standard()
														 : solidity::frontend::OptimiserSettings::
															 minimal();

	if (m_options.optimizer.expectedExecutionsPerDeployment.has_value())
		settings.expectedExecutionsPerDeployment = m_options.optimizer
													   .expectedExecutionsPerDeployment.value();
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
	m_compiler->compile();
	m_compiler->ast("ERC20.sol").accept(*this);
	
	std::vector<std::string> storageVars;
	std::ostringstream		 contractDefinition;
	contractDefinition << m_baseFileName.string() << ":" << m_mainContract;
	auto stateVars	   = m_compiler->contractDefinition(contractDefinition.str()).stateVariables();
	m_definedFunctions = m_compiler->contractDefinition(contractDefinition.str())
							 .definedFunctions();
	auto contractNames = m_compiler->contractNames();
	for (auto name: contractNames)
	{
		auto subNodes = m_compiler->contractDefinition(name).subNodes();
		std::cout << subNodes.size() << std::endl;
		auto functionCalls = solidity::frontend::ASTNode::filteredNodes<
			solidity::frontend::FunctionCall>(subNodes);
		std::cout << functionCalls.size() << std::endl;
		m_contracts[name] = ContractData{
			.subNodes	   = subNodes,
			.functionCalls = functionCalls,
		};
	}
	m_storageVars_astNodes = stateVars;
	for (auto var: stateVars)
	{
		storageVars.emplace_back(var->name());
	}
	// static FunctionDefinition const* resolveFunctionCall(FunctionCall const& _functionCall,
	// ContractDefinition const* _mostDerivedContract);
}