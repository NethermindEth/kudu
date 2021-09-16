#pragma once

#include <liblangutil/ErrorReporter.h>
#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/parsing/Parser.h>

using namespace std;
using namespace solidity;
using namespace solidity::frontend;

#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <cstdlib>
#include <memory>
#include <string>

#include "library.h"


template<class T>
std::string type_name()
{
	typedef typename std::remove_reference<T>::type TR;
	std::unique_ptr<char, void (*)(void*)> own(
#ifndef _MSC_VER
		abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
#else
		nullptr,
#endif
		std::free);
	std::string r = own != nullptr ? own.get() : typeid(TR).name();
	if (std::is_const<TR>::value)
		r += " const";
	if (std::is_volatile<TR>::value)
		r += " volatile";
	if (std::is_lvalue_reference<T>::value)
		r += "&";
	else if (std::is_rvalue_reference<T>::value)
		r += "&&";
	return r;
}

struct PublicFunctions
{
	vector<string> names;
	vector<string> parameters;
	vector<string> hashes;
};

class WarpVisitor: public frontend::ASTVisitor
{
public:
	WarpVisitor(string src, string filepath) 
	{ 
		m_src = src; 
		m_filepath = filepath;
		// removeDuplicates(m_publicFunctions.hashes);
	}
	// vector<string> getPublicFunchashes(size_t numberOfFuncs, const string& contract_path)
	// {
	// 	std::ostringstream cmd;
	// 	std::vector<string> hashes;
	// 	cmd << "solc --combined-json hashes " << contract_path;
	// 	json res = json::parse(exec(cmd.str()));
	// 	auto contracts = res["contracts"];
	// 	for (auto contract: contracts)
	// 	{
	// 		for (auto hash: contract["hashes"].items())
	// 		{
	// 			hashes.emplace_back(hash.value());
	// 		}
	// 	}
	// 	return hashes;
	// }
	// void removeDuplicates(vector<string>& vec)
	// {
	// 	std::sort(vec.begin(), vec.end());
	// 	auto res = vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	// 	cout << *res << endl;
	// }
	// [[nodiscard]] bool visit(FunctionDefinition const& _node) override
	// {
	// 	if (isPublic(_node.visibility()))
	// 	{
	// 		m_publicFunctionCount++;
	// 		int paramsStart = _node.parameterList().location().start + 1;
	// 		int paramsEnd = _node.parameterList().location().end - 1;
	// 		string params = string(m_src.begin() + paramsStart, m_src.begin() + paramsEnd);
	// 		this->m_publicFunctions.names.emplace_back(_node.name());
	// 		this->m_publicFunctions.parameters.emplace_back(params);
	// 	}
	// 	return true;
	// }

	// [[nodiscard]] bool isPublic(Visibility _visibility)
	// {
	// 	switch (_visibility)
	// 	{
	// 	case frontend::Visibility::Public:
	// 		return true;
	// 	default:
	// 		return false;
	// 	}
	// }
	// int m_publicFunctionCount;
	// PublicFunctions m_publicFunctions;
	string m_filepath;
	string m_src;

	bool visit(VariableDeclaration& _node) override
	{
		ASTVisitor::visitNode(_node);
		cout << "name: " << _node.name() +"\n" << _node.isCallableOrCatchParameter() << endl;
		// if (isStorageVar(_node.referenceLocation()))
		// {
		// 	m_storage_vars.emplace_back(std::make_pair(_node.name(),_node.externalIdentifierHex()));
		// }
		return visitNode(_node);
	}

	bool isStorageVar(VariableDeclaration::Location _loc)
	{
		switch (_loc)
		{
		case VariableDeclaration::Location::Storage:
		{
			cout << "STORAGE" << endl;
			return true;
			break;
		}
		case VariableDeclaration::Location::Unspecified:
		{
			cout << "Unspecified" << endl;
			return false;
			break;
		}
		case VariableDeclaration::Location::Memory:
		{
			cout << "Memory" << endl;
			return false;
			break;
		}
		default:
		{
			return false;
			break;
		}
		}

	}
	vector<std::pair<string,string>> m_storage_vars;


};
