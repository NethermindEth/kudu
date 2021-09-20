#pragma once
#include <iostream>
#include <string>

#include <libsolidity/interface/OptimiserSettings.h>
#include <solc/CommandLineInterface.h>


class StorageVars
{
public:
	StorageVars(std::string main_contract, const char* sol_filepath);
	solidity::frontend::CommandLineInterface getCli(char const* sol_filepath);
	std::vector<std::string>				 getStorageVars(const char* sol_filepath);
	std::vector<std::string>				 m_storageVars_str;
	std::string								 m_contractDef;
	std::unique_ptr<solidity::frontend::CompilerStack> m_compiler;
	boost::filesystem::path					 m_baseFileName;

	std::vector<const solidity::frontend::VariableDeclaration*> m_storageVars_astNodes;
};