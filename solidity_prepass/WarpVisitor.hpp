#pragma once

#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/interface/OptimiserSettings.h>
#include <libsolidity/parsing/Parser.h>
#include <solc/CommandLineInterface.h>

#include <string>

#include "common/json.hpp"
using json = nlohmann::json;
using namespace solidity::frontend;
struct PublicFunctions
{
	std::vector<std::string> names;
	std::vector<std::string> parameters;
	std::vector<std::string> hashes;
	std::vector<std::string> sigs;
	std::vector<std::string> markedSigs;
	std::vector<std::string> sigsToReplace;
};

struct ContractData
{
	std::vector<ASTPointer<ASTNode>> subNodes;
	std::vector<FunctionCall const*> functionCalls;
};

struct MarkedFunctions
{
	std::vector<std::string>								  names;
	std::vector<std::vector<ASTPointer<VariableDeclaration>>> parameters;
};


class SourceData: public ASTConstVisitor
{
public:
	SourceData(std::string main_contract, std::string src, std::string filepath);

	CommandLineInterface getCli(char const* sol_filepath);

	std::vector<std::string> getPublicFunchashes(const std::string& contract_path);
	std::string				 exec(std::string cmdStr);

	int	 getSigEnd(int start);
	bool visit(FunctionDefinition const& _node) override;
	bool visit(FunctionCall const& _node) override;
	bool visitNode(ASTNode const& node) override;
	bool contains_warp(std::vector<std::string> vec, std::string search);
	void setSourceData(const char* sol_filepath);
	void makeFunNamesUnique();
	void processChanges();
	void writeModifiedSolidity();
	void compressSigs();

	std::vector<std::string>			m_storageVars_str;
	std::vector<std::string>			m_srcSplit;
	std::vector<std::string>			m_functionNames;
	std::map<std::string, ContractData> m_contracts;
	boost::filesystem::path				m_baseFileName;

	std::string m_mainContract;
	std::string m_contractDef;
	std::string m_filepath;
	std::string m_modifiedSolFilepath;
	std::string m_src;

	std::vector<const FunctionDefinition*> m_definedFunctions;
	void								   test(const ContractDefinition& c, FunctionCall const& f);
	std::unique_ptr<CompilerStack>		   m_compiler;
	std::vector<const VariableDeclaration*> m_storageVars_astNodes;

private:
	bool isPublic(Visibility _visibility);
	bool hasDynamicArgs(std::string params);
	void getDynFunctions();
	void markDynFunctions(std::string find, std::string replace);
	void removeDuplicates();

	std::vector<std::string> m_storageVars;
	std::vector<std::string> m_hashNames;
	PublicFunctions			 m_publicFunctions;
	MarkedFunctions			 m_markedFunctions;
	int						 m_publicFunctionCount;
};
