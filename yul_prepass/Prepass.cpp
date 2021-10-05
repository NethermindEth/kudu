#include "Prepass.hpp"
#include <libyul/Utilities.h>

using namespace boost;


Prepass::Prepass(std::string			  sol_src,
				 std::string			  main_contract,
				 std::string			  contractPath,
				 std::vector<std::string> storageVars)
{
	std::vector<std::string> a = {"hello", "world"};
	this->m_contractPath	   = contractPath;
	this->m_storageVars		   = storageVars;
	this->getPublicFunchashes(contractPath);
	std::vector<std::string> lines = splitStr(sol_src);
	std::ostringstream		 search;
	search << "contract " << main_contract;
	for (size_t i = 0; i < lines.size(); ++i)
	{
		if (lines[i].find(search.str()) != std::string::npos)
		{
			this->m_solSrcLines_mainContract = std::vector<std::string>(
				lines.begin() + i,
				lines.end());
			break;
		}
	}
	this->m_unMarkedSolSource = sol_src;
}

bool isFunctionSig(std::string line)
{
	if (line.find("function ") != std::string::npos
		and line.find("(") != std::string::npos)
	{
		return true;
	}
	return false;
}


bool Prepass::isRuntimeObj(std::string str)
{
	return ((str.find('{')) != std::string::npos)
		   && (str.find("object") != std::string::npos)
		   && (str.find("_deployed") != std::string::npos);
}

std::vector<std::string> Prepass::removePreamble(std::vector<std::string> lines)
{
	for (size_t i = 0; i != lines.size(); ++i)
	{
		if (lines[i].find("object") != std::string::npos)
		{
			return std::vector<std::string>(lines.begin() + i, lines.end());
		}
		else
		{
			continue;
		}
	}
	assert(0 == 1);
	return std::vector<std::string>();
}

std::vector<std::string> Prepass::getRuntimeYul(std::vector<std::string> yul)
{
	std::vector<std::string> lines		= removePreamble(yul);
	int						 start		= lines[0].find("\"");
	int						 end		= lines[0].find("\"", start + 1);
	std::string				 objectName = lines[0].substr(start, end - start);
	std::string deployedObjName			= "object " + objectName + "_deployed";
	trim(deployedObjName);

	for (std::size_t i = 0; i < lines.size(); i++)
	{
		std::string lineCopy = lines[i];
		trim(lineCopy);
		if (isRuntimeObj(lineCopy))
		{
			std::vector<std::string> runtimeObj = std::vector<std::string>(
				lines.begin() + i,
				lines.end());
			runtimeObj.insert(runtimeObj.begin(), lines[0]);
			return runtimeObj;
		}
	}
	return lines;
}


FinalizedYul Prepass::removeDeploymentCode(std::vector<std::string> code)
{
	std::vector<std::string> cleanedCode;
	int						 start = 0;
	for (std::size_t i = 1; i != code.size(); ++i)
	{
		std::string lineCopy = code[i];
		trim(lineCopy);
		if (std::string(lineCopy.begin(), lineCopy.begin() + 8) == "function")
		{
			start = i;
			break;
		}
	}
	auto onlyDefinitions = std::vector<std::string>(code.begin() + start,
													code.end());
	auto entrySequence	 = std::vector<std::string>(code.begin() + 3,
													code.begin() + start);
	int	 entrySeqEnd = std::distance(code.begin() + 3, code.begin() + start);
	entrySequence.insert(entrySequence.begin(),
						 std::string("\t\t\tfunction fun_ENTRY_POINT()"));
	onlyDefinitions.insert(onlyDefinitions.begin(),
						   code.begin(),
						   code.begin() + 3);
	return FinalizedYul{onlyDefinitions, entrySequence, entrySeqEnd};
}

struct EntrySeqData
{
	std::vector<std::string> preSwitchDeclrs;
	int						 switchStart;
};

int Prepass::getSwitchStart(const std::vector<std::string>& func)
{
	for (size_t i = 0; i < func.size(); ++i)
	{
		if (func[i].find("switch _") != std::string::npos)
		{
			return i;
		}
	}
	BOOST_THROW_EXCEPTION(
		std::runtime_error{"failed to find the start of switch statement"});
}


std::vector<std::string> Prepass::getEndOfOjbect(std::vector<std::string> lines)
{
	int end = 0;
	for (std::size_t i = 0; i < lines.size(); i++)
	{
		std::string lineCopy = lines[i];
		trim(lineCopy);
		if (lineCopy.find("Optimized IR") != std::string::npos)
		{
			end = i;
			break;
		}
	}
	if (end == 0)
	{
		return lines;
	}
	return std::vector<std::string>(lines.begin(), lines.begin() + end);
}

std::vector<std::string> Prepass::getMainObject(std::string	 code,
												std::string& main_contract)
{
	trim(main_contract);
	std::transform(main_contract.begin(),
				   main_contract.end(),
				   main_contract.begin(),
				   [](unsigned char c) { return std::tolower(c); });
	auto lines = splitStr(code);
	int	 start = 0;
	for (std::size_t i = 0; i < lines.size(); i++)
	{
		std::string lineCopy = lines[i];
		trim(lineCopy);
		std::transform(lineCopy.begin(),
					   lineCopy.end(),
					   lineCopy.begin(),
					   [](unsigned char c) { return std::tolower(c); });
		if (lineCopy.find(main_contract) != std::string::npos)
		{
			start = int(i) - 1;
			break;
		}
	}
	auto res = std::vector<std::string>(lines.begin() + start, lines.end());
	return getEndOfOjbect(res);
}

std::string Prepass::removeNonDynamicDispatch(std::vector<std::string> entrySeq)
{
	auto		newEntrySeq = concatCaseBlocks(entrySeq);
	std::string prefix;
	std::find_if(entrySeq.begin(),
				 entrySeq.end(),
				 [&prefix](const std::string& line)
				 {
					 if (line.find("switch") != std::string::npos)
					 {
						 prefix += line + "\n";
						 return true;
					 }
					 else
					 {
						 prefix += line + "\n";
						 return false;
					 }
				 });
	std::string entryStr;
	for (size_t i = 0; i < newEntrySeq.size(); i++)
	{
		if (newEntrySeq[i].find("case") != std::string::npos)
		{
			auto selectorInEntrySeq = newEntrySeq[i].substr(
				newEntrySeq[i].find("0x") + 2,
				8);
			auto it	  = std::find(m_publicFunctionSelectors.selectors.begin(),
								  m_publicFunctionSelectors.selectors.end(),
								  selectorInEntrySeq);
			bool isEq = it != m_publicFunctionSelectors.selectors.end();
			int	 idx;
			if (isEq)
				idx = it - m_publicFunctionSelectors.selectors.begin();
			else
				continue;

			auto funName = m_publicFunctionSelectors.functionNames[idx];
			if (isEq and (funName.find("_dynArgs") != std::string::npos))
			{
				entryStr += newEntrySeq[i] + "\n";
			}
			else
			{
				continue;
			}
		}
	}
	std::vector<int> idxs = {4, 3, 2};
	for (auto idx: idxs)
	{
		if (entrySeq[entrySeq.size() - idx].find("revert_")
			!= std::string::npos)
		{
			continue;
		}
		else
		{
			entryStr += entrySeq[entrySeq.size() - idx] + "\n";
		}
	}
	entryStr = prefix + entryStr;
	if (entryStr.find("case") == std::string::npos)
		return "";
	return entryStr;
}

std::vector<std::string>
Prepass::concatCaseBlocks(std::vector<std::string> entrySeq)
{
	std::vector<std::string> newSeq;
	int						 increment = 1;
	for (size_t i = 0; i < entrySeq.size(); i += increment)
	{
		if (entrySeq[i].find("case") != std::string::npos)
		{
			std::string singleStr;
			std::tie(singleStr, increment) = endOfCaseBlock(entrySeq, i + 1);
			singleStr					   = entrySeq[i] + "\n" + singleStr;
			newSeq.emplace_back(singleStr);
		}
	}
	return newSeq;
}

std::pair<std::string, int>
Prepass::endOfCaseBlock(std::vector<std::string> caseBlock, int startPos)
{
	for (size_t i = startPos; i < caseBlock.size(); i++)
	{
		if (caseBlock[i].find("case") != std::string::npos)
		{
			auto block = std::vector<std::string>(caseBlock.begin() + startPos,
												  caseBlock.begin() + i);
			std::string strRepr;
			std::for_each(block.begin(),
						  block.end(),
						  [&strRepr](std::string line)
						  { strRepr += line + "\n"; });
			return std::pair<std::string, int>(strRepr, i - startPos + 1);
		}
		else if (caseBlock[i].find("return") != std::string::npos
				 and caseBlock[i + 2].find("case") == std::string::npos)
		{
			auto block = std::vector<std::string>(caseBlock.begin() + startPos,
												  caseBlock.begin() + i + 2);
			std::string strRepr;
			std::for_each(block.begin(),
						  block.end(),
						  [&strRepr](std::string line)
						  { strRepr += line + "\n"; });
			return std::pair<std::string, int>(strRepr, i - startPos + 1);
		}
	}
	throw std::runtime_error("Could not find end of case block");
	return std::pair<std::string, int>("", -1);
}

void Prepass::getPublicFunchashes(const std::string& contract_path)
{
	std::ostringstream cmd;
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
				this->m_publicFunctionSelectors.functionNames.emplace_back(
					name);
				this->m_publicFunctionSelectors.selectors.emplace_back(
					hash.value());
			}
		}
	}
}

std::string Prepass::exec(std::string cmdStr)
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

bool Prepass::isExtCodeSizeCheck(std::array<std::string, 6> lines)
{
	return (lines[0].find("extcodesize") != std::string::npos
			and lines[1].find("iszero") != std::string::npos
			and lines[2].find("if") != std::string::npos
			and lines[3].find("{") != std::string::npos
			and lines[4].find("revert") != std::string::npos
			and lines[5].find("}") != std::string::npos);
}

std::vector<std::string>
Prepass::removeExtCodeSizeCheck(std::vector<std::string> yul)
{
	size_t					 increment = 1;
	std::vector<std::string> result;
	for (size_t i = 0; i < yul.size(); i += increment)
	{
		if (i + 6 < yul.size())
		{
			std::array<std::string, 6> seq = {yul[i],
											  yul[i + 1],
											  yul[i + 2],
											  yul[i + 3],
											  yul[i + 4],
											  yul[i + 5]};
			if (isExtCodeSizeCheck(seq))
			{
				increment = 6;
			}
			else
			{
				result.emplace_back(yul[i]);
				increment = 1;
			}
		}
		else
		{
			increment = 1;
			result.emplace_back(yul[i]);
		}
	}
	return result;
}

std::string Prepass::addEntryFunc(std::vector<std::string> entrySeq,
								  std::vector<std::string> cleanCode)
{
	// So we can look ahead by 2 and still make
	// sure we read all the generated Yul.
	cleanCode.push_back("\n");
	cleanCode.push_back("\n");
	std::string yulStr;
	auto		entryStr = removeNonDynamicDispatch(entrySeq);
	for (size_t i = 0; i < cleanCode.size() - 2; i++)
	{
		yulStr += cleanCode[i] + "\n";
		if (cleanCode[i + 2].find("data \".metadata\" hex\"")
			!= std::string::npos)
		{
			yulStr += entryStr + "\n";
		}
	}
	return solidity::yul::reindent(yulStr);
}

std::string Prepass::cleanYul(std::string code, std::string& main_contract)
{
	auto yul		= getMainObject(code, main_contract);
	auto runtimeYul = getRuntimeYul(yul);
	runtimeYul		= removeExtCodeSizeCheck(runtimeYul);
	std::vector<std::string> clean;
	std::vector<std::string> entry;
	FinalizedYul			 finalYul = removeDeploymentCode(runtimeYul);
	clean							  = finalYul.onlyDefinitions;
	entry							  = finalYul.entrySequence;
	auto placeHolder				  = "\tcode {\n\t\t//holder\n\t}\n";
	clean.insert(clean.begin() + 1, placeHolder);
	auto complete = addEntryFunc(entry, clean);
	return complete;
}
