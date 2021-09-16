
#include "Prepass.h"
#include <set>
#include <sstream>

using namespace std;
using namespace boost;

Prepass::Prepass(string sol_src, string main_contract, string contractPath)
{
	this->m_contractPath = contractPath;
	auto lines = splitStr(sol_src);
	std::ostringstream search;
	search << "contract " << main_contract;
	for (auto i = 0; i < lines.size(); ++i)
	{
		if (lines[i].find(search.str()) != string::npos)
		{
			this->m_solSrcLines_mainContract = vector<string>(lines.begin() + i, lines.end());
			break;
		}
	}
	this->m_unMarkedSolSource = sol_src;
	// for (auto line: m_solSrcLines)
	// {

	// }
}

bool isFunctionSig(string line)
{
	if (line.find("function ") != string::npos and line.find("(") != string::npos)
	{
		return true;
	}
	return false;
}

void Prepass::tester()
{
	this->getPublicFunctions();
	for (auto i = 0; i < m_solSrcLines_mainContract.size(); ++i)
	{
		if (isFunctionSig(m_solSrcLines_mainContract[i]))
		{
			int start, end;
			auto lines = vector<string>(m_solSrcLines_mainContract.begin() + i, m_solSrcLines_mainContract.end());
			std::tie(start, end) = getFuncSigRange(lines, i);
		}
	}
}
std::pair<int, int> Prepass::getFuncSigRange(vector<string> lines, int start)
{
	for (auto i = 0; i < lines.size(); ++i)
	{
		if (lines[i].find("{") != string::npos)
		{
			return std::make_pair(start, start + i);
		}
	}
	BOOST_THROW_EXCEPTION(std::runtime_error{"Failed to find end of function signature"});
}

string Prepass::exec(string cmdStr)
{
	const char* cmd = cmdStr.c_str();
	std::array<char, 4096> buffer;
	string result;
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

string Prepass::getFunctionName(string funcSig)
{
	auto paramsStart = funcSig.find('(');
	auto paramsEnd = funcSig.find(')');
	auto safetyCheckLPAREN = std::count(funcSig.begin(), funcSig.begin() + paramsEnd, '(');
	auto safetyCheckRPAREN = std::count(funcSig.begin(), funcSig.begin() + paramsEnd, ')');
	assert(safetyCheckRPAREN + safetyCheckLPAREN == 2);
	return string(funcSig.begin(), funcSig.begin() + paramsStart);
}

void Prepass::getPublicFunctions()
{
	std::ostringstream cmd;
	cmd << "solc --combined-json hashes " << this->m_contractPath;
	json res = json::parse(exec(cmd.str()));
	auto contracts = res["contracts"];
	Selectors selectors = Selectors{};
	for (auto contract: contracts)
	{
		for (auto hash: contract["hashes"].items())
		{
			selectors.hashes.emplace_back(hash.value());
			selectors.names.emplace_back(getFunctionName(hash.key()));
		}
	}
	std::sort(selectors.hashes.begin(), selectors.hashes.end());
	selectors.hashes.erase(std::unique(selectors.hashes.begin(), selectors.hashes.end()), selectors.hashes.end());
	std::sort(selectors.names.begin(), selectors.names.end());
	selectors.names.erase(std::unique(selectors.names.begin(), selectors.names.end()), selectors.names.end());
	this->m_selectors = selectors;
}


string Prepass::markDynamicFunctions(string solidity_src) {}

bool Prepass::isRuntimeObj(string str)
{
	return ((str.find('{')) != string::npos) && (str.find("object") != string::npos)
		   && (str.find("_deployed") != string::npos);
}

vector<string> Prepass::removePreamble(vector<string> lines)
{
	for (size_t i = 0; i != lines.size(); ++i)
	{
		if (lines[i].find("object") != string::npos)
		{
			return vector<string>(lines.begin() + i, lines.end());
		}
		else
		{
			continue;
		}
	}
	assert(0 == 1);
	return vector<string>();
}

vector<string> Prepass::getRuntimeYul(vector<string> yul)
{
	vector<string> lines = removePreamble(yul);
	int start = lines[0].find("\"");
	int end = lines[0].find("\"", start + 1);
	string objectName = lines[0].substr(start, end - start);
	string deployedObjName = "object " + objectName + "_deployed";
	// replace(deployedObjName.begin(), deployedObjName.end(), '\"', '\0');
	trim_left(deployedObjName);
	trim_right(deployedObjName);

	for (size_t i = 0; i < lines.size(); i++)
	{
		string lineCopy = lines[i];
		// replace(lineCopy.begin(), lineCopy.end(), '\"', '\0');
		trim_left(lineCopy);
		trim_right(lineCopy);
		if (isRuntimeObj(lineCopy))
		{
			vector<string> runtimeObj = vector<string>(lines.begin() + i, lines.end());
			runtimeObj.insert(runtimeObj.begin(), lines[0]);
			return runtimeObj;
		}
	}
	return lines;
}


FinalizedYul Prepass::removeDeploymentCode(vector<string> code)
{
	vector<string> cleanedCode;
	int start = 0;
	for (size_t i = 1; i != code.size(); ++i)
	{
		string lineCopy = code[i];
		trim_left(lineCopy);
		trim_right(lineCopy);
		if (string(lineCopy.begin(), lineCopy.begin() + 8) == "function")
		{
			start = i;
			break;
		}
	}
	auto onlyDefinitions = vector<string>(code.begin() + start, code.end());
	auto entrySequence = vector<string>(code.begin() + 3, code.begin() + start);
	int entrySeqEnd = std::distance(code.begin() + 3, code.begin() + start);
	entrySequence.insert(entrySequence.begin(), std::string("\t\t\tfunction fun_ENTRY_POINT()"));
	onlyDefinitions.insert(onlyDefinitions.begin(), code.begin(), code.begin() + 3);
	return FinalizedYul{.onlyDefinitions = onlyDefinitions, .entrySequence = entrySequence, .entrySeqEnd = entrySeqEnd};
}

struct EntrySeqData
{
	vector<string> preSwitchDeclrs;
	int switchStart;
};

int Prepass::getSwitchStart(const vector<string>& func)
{
	for (auto i = 0; i < func.size(); ++i)
	{
		if (func[i].find("switch _") != string::npos)
		{
			return i;
		}
	}
	BOOST_THROW_EXCEPTION(std::runtime_error{"failed to find the start of switch statement"});
}

vector<string> Prepass::cleanEntryFunction(vector<string> func, int funcEnd)
{
	EntrySeqData entrySeqData;
	entrySeqData.switchStart = getSwitchStart(func);
	for (auto i = 0; i < func.size(); ++i)
	{
	}
}

vector<string> Prepass::splitStr(const string& str)
{
	vector<string> strings;

	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = str.find('\n', prev)) != string::npos)
	{
		strings.push_back(str.substr(prev, pos - prev));
		prev = pos + 1;
	}

	// To get the last substring (or only, if delimiter is not found)
	strings.push_back(str.substr(prev));

	return strings;
}

vector<string> Prepass::getEndOfOjbect(vector<string> lines)
{
	int end = 0;
	for (size_t i = 0; i < lines.size(); i++)
	{
		string lineCopy = lines[i];
		trim_left(lineCopy);
		trim_right(lineCopy);
		if (lineCopy.find("Optimized IR") != string::npos)
		{
			end = i;
			break;
		}
	}
	if (end == 0)
	{
		return lines;
	}
	return vector<string>(lines.begin(), lines.begin() + end);
}

vector<string> Prepass::getMainObject(string code, string& main_contract)
{
	trim_left(main_contract);
	trim_right(main_contract);
	std::transform(
		main_contract.begin(),
		main_contract.end(),
		main_contract.begin(),
		[](unsigned char c) { return std::tolower(c); });
	auto lines = splitStr(code);
	int start = 0;
	for (size_t i = 0; i < lines.size(); i++)
	{
		string lineCopy = lines[i];
		trim_left(lineCopy);
		trim_right(lineCopy);
		std::transform(
			lineCopy.begin(), lineCopy.end(), lineCopy.begin(), [](unsigned char c) { return std::tolower(c); });
		if (lineCopy.find(main_contract) != string::npos)
		{
			start = int(i) - 1;
			break;
		}
	}
	auto res = vector<string>(lines.begin() + start, lines.end());
	return getEndOfOjbect(res);
}

string Prepass::addEntryFunc(vector<string> entrySeq, vector<string> cleanCode)
{
	string entryStr;
	// So we can look ahead by 2 and still make
	// sure we read all the generated Yul.
	cleanCode.push_back("\n");
	cleanCode.push_back("\n");
	string yulStr;
	for (auto line: entrySeq)
	{
		entryStr += line + "\n";
	}
	// cout << entryStr << endl;
	for (auto i = 0; i < cleanCode.size() - 2; i++)
	{
		yulStr += cleanCode[i] + "\n";
		if (cleanCode[i + 2].find("data \".metadata\" hex\"") != string::npos)
		{
			yulStr += entryStr + "\n";
		}
	}
	return yulStr;
}
string Prepass::cleanYul(string code, string& main_contract)
{
	auto yul = getMainObject(code, main_contract);
	auto runtimeYul = getRuntimeYul(yul);
	vector<string> clean;
	vector<string> entry;
	FinalizedYul finalYul = removeDeploymentCode(runtimeYul);
	clean = finalYul.onlyDefinitions;
	entry = finalYul.entrySequence;
	auto placeHolder = "\tcode {\n\t\t//holder\n\t}\n";
	clean.insert(clean.begin() + 1, placeHolder);
	auto complete = addEntryFunc(entry, clean);
	return complete;
}