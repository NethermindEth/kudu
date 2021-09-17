#pragma once

#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/parsing/Parser.h>

#include <string>

#include "StorageVariables.hpp"
#include "json.hpp"
using json = nlohmann::json;


struct PublicFunctions
{
	std::vector<std::string> names;
	std::vector<std::string> parameters;
	std::vector<std::string> hashes;
	std::vector<std::string> sigs;
	std::vector<std::string> markedSigs;
	std::vector<std::string> sigsToReplace;
};

class WarpVisitor: public solidity::frontend::ASTConstVisitor
{
public:
	WarpVisitor(std::string main_contract, std::string src, std::string filepath)
	{
		m_src		  = src;
		m_filepath	  = filepath;
		m_storageVars = StorageVars(main_contract, filepath.c_str()).m_storageVars_str;
		m_publicFunctions.hashes = this->getPublicFunchashes(filepath);
		// removeDuplicates();
	}

	std::vector<std::string> getPublicFunchashes(const std::string& contract_path);
	std::string				 exec(std::string cmdStr);
	bool visit(solidity::frontend::FunctionDefinition const& _node) override;
	bool visitNode(solidity::frontend::ASTNode const& node) override;
	bool contains_warp(std::vector<std::string> vec, std::string search);
	bool isPublic(solidity::frontend::Visibility _visibility);
	bool hasDynamicArgs(std::string params);
	void getDynFunctions();
	void markDynFunctions();
	void removeDuplicates();

	int						 m_publicFunctionCount;
	PublicFunctions			 m_publicFunctions;
	std::vector<std::string> m_storageVars;
	std::vector<std::string> m_hashNames;
	std::string				 m_filepath;
	std::string				 m_src;
};
