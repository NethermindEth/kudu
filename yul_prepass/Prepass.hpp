#pragma once
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/throw_exception.hpp>
#include <cassert>
#include <cctype>
#include <iostream>
#include <locale>
#include <set>
#include <vector>

#include "common/json.hpp"
#include "common/library.hpp"
using json = nlohmann::json;

struct FinalizedYul
{
	std::vector<std::string> onlyDefinitions;
	std::vector<std::string> entrySequence;
	int						 entrySeqEnd;
};

struct Selectors
{
	std::vector<std::string> functionNames;
	std::vector<std::string> selectors;
};

class Prepass
{
public:
	std::string cleanYul(std::string code, std::string& main_contract);
	Prepass(std::string				 sol_src,
			std::string				 main_contract,
			std::string				 contractPath,
			std::vector<std::string> storageVars);
	void tester();

private:
	std::vector<std::string> removePreamble(std::vector<std::string> lines);
	std::vector<std::string> getRuntimeYul(std::vector<std::string> yul);
	std::vector<std::string> getEndOfOjbect(std::vector<std::string> lines);
	std::vector<std::string>
	concatCaseBlocks(std::vector<std::string> entrySeq);
	std::vector<std::string> getMainObject(std::string	code,
										   std::string& main_contract);

	std::vector<std::string>
				 removeExtCodeSizeCheck(std::vector<std::string> yul);
	void		 getPublicFunchashes(const std::string& contract_path);
	bool		 isRuntimeObj(std::string str);
	bool		 isExtCodeSizeCheck(std::array<std::string, 6> lines);
	int			 getSwitchStart(const std::vector<std::string>& func);
	FinalizedYul removeDeploymentCode(std::vector<std::string> code);
	std::string	 removeNonDynamicDispatch(std::vector<std::string> entrySeq);
	std::string	 exec(std::string cmdStr);
	std::pair<std::string, int>
	endOfCaseBlock(std::vector<std::string> caseBlock, int startPos);
	std::string addEntryFunc(std::vector<std::string> entrySeq,
							 std::vector<std::string> cleanCode);

	std::string				 m_unMarkedSolSource;
	std::string				 m_markedSolSource;
	std::string				 m_contractPath;
	std::vector<std::string> m_storageVars;
	std::vector<std::string> m_solSrcLines_mainContract;
	std::vector<std::string> m_solSrcLines_full;
	Selectors				 m_publicFunctionSelectors;
};