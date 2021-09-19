#include <boost/algorithm/string.hpp>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/codegen/ir/IRGenerator.h>
#include <libsolutil/IndentedWriter.h>
#include <libyul/AsmJsonConverter.h>
#include <regex>
#include <tools/yulPhaser/Program.h>

#include "WarpVisitor.hpp"
#include "yul_prepass/Prepass.hpp"

SourceData::SourceData(std::string main_contract, std::string src, std::string filepath)
{
	m_src					 = src;
	m_filepath				 = filepath;
	m_mainContract			 = main_contract;
	m_modifiedSolFilepath	 = std::string(filepath.begin(), filepath.end() - 4) + "_marked.sol";
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

bool SourceData::visitNode(ASTNode const& node) { return ASTConstVisitor::visitNode(node); }

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

[[nodiscard]] bool SourceData::visit(FunctionDefinition const& _node)
{
	switch (m_currentPass)
	{
	case PassType::FunctionDefinitionVisitor:
	{
		m_functionNames.push_back(_node.name());
		if (_node.isConstructor())
			return visitNode(_node);
		try
		{
			if (isPublic(_node.visibility()))
			{
				int	 paramsStart   = _node.parameterList().location().start + 1;
				int	 paramsEnd	   = _node.parameterList().location().end - 1;
				int	 functionStart = _node.location().start;
				int	 functionEnd   = _node.location().end;
				int	 bodyStart	   = _node.body().location().start;
				int	 bodyEnd	   = _node.body().location().end;
				auto body = std::string(m_src.begin() + bodyStart + 1, m_src.begin() + bodyEnd);
				auto funcLocation = std::make_pair(functionStart, functionEnd);
				auto params = std::string(m_src.begin() + paramsStart, m_src.begin() + paramsEnd);
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
					m_markedFunctions.names.emplace_back(_node.name());
					std::vector<Type const*> params;
					for (auto param: _node.parameters())
					{
						params.emplace_back(param->type());
					}
					m_markedFunctions.parameters.emplace_back(params);
					m_markedFunctions.selectors.emplace_back(_node.externalIdentifierHex());
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
	default:
		return visitNode(_node);
	}
}

[[nodiscard]] bool SourceData::isPublic(Visibility _visibility)
{
	switch (_visibility)
	{
	case Visibility::Public:
	case Visibility::External:
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

CommandLineInterface SourceData::getCli(char const* sol_filepath)
{
	std::string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
	std::erase(yulOptimiserSteps, 'i'); // remove FullInliner
	yulOptimiserSteps += " x";			// that flattens function calls: only one
										// function call per statement is allowed
	constexpr int solc_argc			   = 2;
	char const*	  solc_argv[solc_argc] = {
		  "--bin",
		  sol_filepath,
	  };

	std::istringstream	 sin; // never used, but the CLI requires it
	std::ostringstream	 sout;
	CommandLineInterface cli{sin, sout, std::cerr};
	if (not cli.parseArguments(solc_argc, solc_argv))
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc CLI failed to parse arguments"});
	if (not cli.readInputFiles())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to read input files"});

	return cli;
}

bool SourceData::visit(FunctionCall const& _node)
{
	switch (m_currentPass)
	{
	case PassType::FunctionCallVisitor:
	{
		auto funcDef = resolveFunctionCall(m_compiler->contractDefinition("ERC20.sol:WARP"), _node);
		if (funcDef != nullptr)
		{
			auto selector = funcDef->externalIdentifierHex();
			int	 found	  = 0;
			std::for_each(m_markedFunctions.selectors.begin(),
						  m_markedFunctions.selectors.end(),
						  [&found, &selector](const std::string& id)
						  { found += int((id == selector)); });
			if (found == 1)
			{
				auto line = std::string(m_src.begin() + _node.location().start,
										m_src.begin() + _node.location().end + 1);
				auto sig  = std::string(
					 m_src.begin() + _node.location().start, m_src.begin() + _node.location().end);
				auto funcName = std::string(sig.begin(), sig.begin() + sig.find('('));
				int	 index	  = 0;
				int	 count	  = 0;
				std::for_each(m_srcSplit.begin(),
							  m_srcSplit.end(),
							  [&index, &line, &count](std::string src)
							  {
								  boost::trim(src);
								  if (line == src)
									  index = count;
								  count++;
							  });
				boost::replace_first(m_srcSplit[index], funcName, funcName + "_dynArgs");
			}
		}
		return visitNode(_node);
	}
	default:
		return visitNode(_node);
	}
}

bool SourceData::checkTypeEqaulity(std::vector<Type const*> const& t1, std::vector<Type const*> t2)
{
	if (t1.size() != t2.size())
		return false;
	else
	{
		for (auto i = 0; i < t1.size(); ++i)
		{
			if (*t1[i] != *t2[i])
				return false;
		}
		return true;
	}
}

FunctionDefinition const* SourceData::resolveFunctionCall(const ContractDefinition& c,
														  FunctionCall const&		f)
{
	return ASTNode::resolveFunctionCall(f, &c);
}

void SourceData::setCompilerOptions(std::shared_ptr<CompilerStack> compiler)
{
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
	compiler->enableIRGeneration(m_options.compiler.outputs.ir
								 || m_options.compiler.outputs.irOptimized);
	compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);

	std::string yulOptimiserSteps = OptimiserSettings::DefaultYulOptimiserSteps;
	std::erase(yulOptimiserSteps, 'i'); // remove FullInliner
	yulOptimiserSteps += " x";			// that flattens function calls: only one

	this->m_compilerOptimizerSettings							= OptimiserSettings::full();
	m_compilerOptimizerSettings.yulOptimiserSteps				= yulOptimiserSteps;
	m_compilerOptimizerSettings.expectedExecutionsPerDeployment = 1;

	m_compiler->setOptimiserSettings(m_compilerOptimizerSettings);
	m_compiler->setSources(m_fileReader.sourceCodes());
	m_compiler->setParserErrorRecovery(m_options.input.errorRecovery);
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

	this->m_fileReader = std::move(cli.fileReader());
	this->m_compiler   = std::make_shared<CompilerStack>(m_fileReader.reader());
	this->m_options	   = cli.options();
	this->setCompilerOptions(m_compiler);

	m_compiler->parse();
	m_compiler->analyze();
	m_compiler->compile();

	m_currentPass = PassType::FunctionDefinitionVisitor;
	m_compiler->ast("ERC20.sol").accept(*this);
	m_currentPass = PassType::FunctionCallVisitor;
	m_compiler->ast("ERC20.sol").accept(*this);

	this->writeModifiedSolidity();

	std::vector<std::string> storageVars;
	std::ostringstream		 contractDefinition;
	contractDefinition << m_baseFileName.string() << ":" << m_mainContract;
	auto stateVars	   = m_compiler->contractDefinition(contractDefinition.str()).stateVariables();
	auto contractNames = m_compiler->contractNames();
	for (auto name: contractNames)
	{
		auto subNodes	   = m_compiler->contractDefinition(name).subNodes();
		auto functionCalls = ASTNode::filteredNodes<FunctionCall>(subNodes);
		m_contracts[name]  = ContractData{
			 .subNodes		= subNodes,
			 .functionCalls = functionCalls,
		 };
	}
	m_storageVars_astNodes = stateVars;
	for (auto var: stateVars)
	{
		storageVars.emplace_back(var->name());
	}

	m_compiler->reset(true);
	cli   = getCli(sol_filepath);
	paths = cli.options().input.paths;
	// For now we are only supporting single files;
	for (auto p: paths)
	{
		this->m_baseFileName = p.filename();
	}

	IRGenerator generator(cli.options().output.evmVersion,
						  cli.options().output.revertStrings,
						  m_compilerOptimizerSettings,
						  m_compiler->sourceIndices());

	std::string yulIR, yulIROptimized;
	auto		otherYulSources = std::map<ContractDefinition const*, std::string_view const>();

	tie(yulIR, yulIROptimized) = generator.run(
		m_compiler->contractDefinition(contractDefinition.str()),
		m_compiler->cborMetadata(contractDefinition.str()),
		otherYulSources);

	auto prepass = Prepass(m_src, m_mainContract, m_modifiedSolFilepath.c_str());
	auto yul	 = prepass.cleanYul(yulIROptimized, m_mainContract);

	// =============== Generate Yul JSON AST ===============
	langutil::CharStream ir = langutil::CharStream(yul, sol_filepath);

	std::variant<phaser::Program, langutil::ErrorList> maybeProgram = phaser::Program::load(ir);

	if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram))
	{
		langutil::SingletonCharStreamProvider streamProvider{ir};
		langutil::SourceReferenceFormatter{std::cerr, streamProvider, true, false}
			.printErrorInformation(*errorList);
		std::cerr << std::endl;
	}

	yul::Block const&	  ast = get<phaser::Program>(maybeProgram).ast();
	yul::AsmJsonConverter jsonConverter{{}};
	std::cout << jsonConverter(ast) << std::endl;
	// std::cout << yulIROptimized << std::endl;
	// static FunctionDefinition const* resolveFunctionCall(FunctionCall const& _functionCall,
	// ContractDefinition const* _mostDerivedContract);
}