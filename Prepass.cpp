#include "Prepass.hpp"
#include "library.hpp"
#include <set>
#include <sstream>

using namespace boost;

Prepass::Prepass(std::string sol_src, std::string main_contract, std::string contractPath)
{
	this->m_contractPath	 = contractPath;
	auto			   lines = splitStr(sol_src);
	std::ostringstream search;
	search << "contract " << main_contract;
	for (auto i = 0; i < lines.size(); ++i)
	{
		if (lines[i].find(search.str()) != std::string::npos)
		{
			this->m_solSrcLines_mainContract
				= std::vector<std::string>(lines.begin() + i, lines.end());
			break;
		}
	}
	this->m_unMarkedSolSource = sol_src;
	// for (auto line: m_solSrcLines)
	// {

	// }
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
	std::vector<std::string> lines			 = removePreamble(yul);
	int						 start			 = lines[0].find("\"");
	int						 end			 = lines[0].find("\"", start + 1);
	std::string				 objectName		 = lines[0].substr(start, end - start);
	std::string				 deployedObjName = "object " + objectName + "_deployed";
	// replace(deployedObjName.begin(), deployedObjName.end(), '\"', '\0');
	trim_left(deployedObjName);
	trim_right(deployedObjName);

	for (std::size_t i = 0; i < lines.size(); i++)
	{
		std::string lineCopy = lines[i];
		// replace(lineCopy.begin(), lineCopy.end(), '\"', '\0');
		trim_left(lineCopy);
		trim_right(lineCopy);
		if (isRuntimeObj(lineCopy))
		{
			std::vector<std::string> runtimeObj
				= std::vector<std::string>(lines.begin() + i, lines.end());
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
		trim_left(lineCopy);
		trim_right(lineCopy);
		if (std::string(lineCopy.begin(), lineCopy.begin() + 8) == "function")
		{
			start = i;
			break;
		}
	}
	auto onlyDefinitions = std::vector<std::string>(code.begin() + start, code.end());
	auto entrySequence = std::vector<std::string>(code.begin() + 3, code.begin() + start);
	int	 entrySeqEnd   = std::distance(code.begin() + 3, code.begin() + start);
	entrySequence
		.insert(entrySequence.begin(), std::string("\t\t\tfunction fun_ENTRY_POINT()"));
	onlyDefinitions.insert(onlyDefinitions.begin(), code.begin(), code.begin() + 3);
	return FinalizedYul{
		.onlyDefinitions = onlyDefinitions,
		.entrySequence	 = entrySequence,
		.entrySeqEnd	 = entrySeqEnd};
}

struct EntrySeqData
{
	std::vector<std::string> preSwitchDeclrs;
	int						 switchStart;
};

int Prepass::getSwitchStart(const std::vector<std::string>& func)
{
	for (auto i = 0; i < func.size(); ++i)
	{
		if (func[i].find("switch _") != std::string::npos)
		{
			return i;
		}
	}
	BOOST_THROW_EXCEPTION(
		std::runtime_error{"failed to find the start of switch statement"});
}

std::vector<std::string>
Prepass::cleanEntryFunction(std::vector<std::string> func, int funcEnd)
{
	EntrySeqData entrySeqData;
	entrySeqData.switchStart = getSwitchStart(func);
	for (auto i = 0; i < func.size(); ++i)
	{
	}
}

std::vector<std::string> Prepass::getEndOfOjbect(std::vector<std::string> lines)
{
	int end = 0;
	for (std::size_t i = 0; i < lines.size(); i++)
	{
		std::string lineCopy = lines[i];
		trim_left(lineCopy);
		trim_right(lineCopy);
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

std::vector<std::string>
Prepass::getMainObject(std::string code, std::string& main_contract)
{
	trim_left(main_contract);
	trim_right(main_contract);
	std::transform(
		main_contract.begin(),
		main_contract.end(),
		main_contract.begin(),
		[](unsigned char c) { return std::tolower(c); });
	auto lines = splitStr(code);
	int	 start = 0;
	for (std::size_t i = 0; i < lines.size(); i++)
	{
		std::string lineCopy = lines[i];
		trim_left(lineCopy);
		trim_right(lineCopy);
		std::transform(
			lineCopy.begin(),
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

std::string Prepass::addEntryFunc(
	std::vector<std::string> entrySeq, std::vector<std::string> cleanCode)
{
	std::string entryStr;
	// So we can look ahead by 2 and still make
	// sure we read all the generated Yul.
	cleanCode.push_back("\n");
	cleanCode.push_back("\n");
	std::string yulStr;
	for (auto line: entrySeq)
	{
		entryStr += line + "\n";
	}
	// cout << entryStr << endl;
	for (auto i = 0; i < cleanCode.size() - 2; i++)
	{
		yulStr += cleanCode[i] + "\n";
		if (cleanCode[i + 2].find("data \".metadata\" hex\"") != std::string::npos)
		{
			yulStr += entryStr + "\n";
		}
	}
	return yulStr;
}

std::string Prepass::cleanYul(std::string code, std::string& main_contract)
{
	auto					 yul		= getMainObject(code, main_contract);
	auto					 runtimeYul = getRuntimeYul(yul);
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