#pragma once
#include "json.hpp"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/throw_exception.hpp>
#include <cassert>
#include <cctype>
#include <iostream>
#include <locale>
#include <set>
#include <vector>

using json = nlohmann::json;
using namespace std;

struct FinalizedYul
{
	vector<string> onlyDefinitions;
	vector<string> entrySequence;
	int entrySeqEnd;
};

struct FunctionSigs
{
	vector<string> names;
	vector<string> parameters;
};

struct EntrySwitchCases
{
};

struct Selectors
{
	vector<string> hashes;
	vector<string> names;
};

class Prepass
{
public:
	string cleanYul(string code, string& main_contract);
	[[nodiscard]] Prepass(string sol_src, string main_contract, string contractPath);
	void tester();

private:
	string exec(string cmdStr);
	string getFunctionName(string functionSig);
	vector<string> splitStr(const string& str);
	bool isRuntimeObj(string str);
	vector<string> removePreamble(vector<string> lines);
	vector<string> getRuntimeYul(vector<string> yul);
	FinalizedYul removeDeploymentCode(vector<string> code);
	vector<string> cleanEntryFunction(vector<string> func, int funcEnd);
	int getSwitchStart(const vector<string>& func);
	vector<string> getEndOfOjbect(vector<string> lines);
	vector<string> getMainObject(string code, string& main_contract);
	std::pair<int, int> getFuncSigRange(vector<string> lines, int start);
	void getPublicFunctions();
	string markDynamicFunctions(string solidity_src);
	string addEntryFunc(vector<string> entrySeq, vector<string> cleanCode);
	string m_unMarkedSolSource;
	string m_markedSolSource;
	string m_contractPath;
	vector<string> m_solSrcLines_mainContract;
	vector<string> m_solSrcLines_full;
	Selectors m_selectors;
	FunctionSigs m_functionSigs;
};