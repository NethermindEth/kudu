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

struct FinalizedYul
{
	std::vector<std::string> onlyDefinitions;
	std::vector<std::string> entrySequence;
	int						 entrySeqEnd;
};

struct EntrySwitchCases
{
};


class Prepass
{
public:
	std::string cleanYul(std::string code, std::string& main_contract);
	[[nodiscard]] Prepass(
		std::string sol_src, std::string main_contract, std::string contractPath);
	void tester();

private:
	std::vector<std::string> removePreamble(std::vector<std::string> lines);
	std::vector<std::string> m_solSrcLines_mainContract;
	std::vector<std::string> m_solSrcLines_full;
	std::vector<std::string> getRuntimeYul(std::vector<std::string> yul);
	std::vector<std::string>
	cleanEntryFunction(std::vector<std::string> func, int funcEnd);
	std::vector<std::string> getEndOfOjbect(std::vector<std::string> lines);
	std::vector<std::string> getMainObject(std::string code, std::string& main_contract);
	bool					 isRuntimeObj(std::string str);
	int						 getSwitchStart(const std::vector<std::string>& func);
	FinalizedYul			 removeDeploymentCode(std::vector<std::string> code);
	std::string
	addEntryFunc(std::vector<std::string> entrySeq, std::vector<std::string> cleanCode);
	std::string	 m_unMarkedSolSource;
	std::string	 m_markedSolSource;
	std::string	 m_contractPath;
};