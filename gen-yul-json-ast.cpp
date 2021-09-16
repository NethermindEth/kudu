#include <boost/exception/diagnostic_information.hpp>
#include <boost/throw_exception.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <variant>

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/interface/OptimiserSettings.h>
#include <libyul/AST.h>
#include <libyul/AsmJsonConverter.h>
#include <solc/CommandLineInterface.h>
#include <tools/yulPhaser/Program.h>

#include "Prepass.h"
#include "WarpVisitor.h"
#include "StorageVariables.hpp"

using namespace solidity;
using namespace solidity::util;
using namespace solidity::langutil;

using namespace solidity::frontend;
using namespace std;
vector<string> splitStr(const string& str);



int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "USAGE: " << argv[0] << " SOLIDITY-FILE " << "MAIN-CONTRACT-NAME" << std::endl;
		std::cerr << "Where MAIN-CONTRACT-NAME is the name of the primary contract (non-interface,  non-library, non-abstract contract)" << std::endl;
		return 1;
	}
	char const* sol_filepath = argv[1];
	string sol_src = slurpFile(sol_filepath);
	string main_contract = argv[2];
	StorageVars storageVars(sol_filepath);
	for (auto var : storageVars.m_storageVars_str)
	{
		cout << var << endl;
	}
	// auto prepass = Prepass(sol_src, main_contract, sol_filepath);
	// prepass.tester();

	// langutil::ErrorList errors;
	// langutil::ErrorReporter errorReporter{errors};
	// frontend::Parser parser{errorReporter, langutil::EVMVersion()};


	// string contractContents = slurpFile(sol_filepath);
	// langutil::CharStream charStream{contractContents, sol_filepath};
	// auto sourceUnit = parser.parse(charStream);

	// SolFunctionVisitor funcVisitor(contractContents, sol_filepath);
	// sourceUnit->accept(funcVisitor);
	// sourceUnit->accept(funcVisitor);
	// cout << funcVisitor.m_publicFunctions.hashes.size() << endl;
	// cout << funcVisitor.m_publicFunctions.names.size() << endl;
	// cout << funcVisitor.m_publicFunctions.parameters.size() << endl;
	// for (auto name : funcVisitor.m_storage_vars)
	// {
	// 	cout << name.first << endl;
	// }
	// auto yul = prepass.cleanYul(irSource, main_contract);
	// auto res = exec("solc --hashes ERC20.sol");
	// auto res2 = string(res.begin() + res.rfind("=") + 1, res.end());
	// auto res3 = string(res2.begin() + res2.find(":") +1, res2.end());
	// auto res4 = splitStr(res3);
	// cout << res4[1] << endl;
	// cout << yul << endl;
	// langutil::CharStream ir = langutil::CharStream(yul, sol_filepath);

	// std::variant<phaser::Program, langutil::ErrorList> maybeProgram
	// 	= phaser::Program::load(ir);
	// if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram))
	// {
	// 	langutil::SingletonCharStreamProvider streamProvider{ir};
	// 	langutil::SourceReferenceFormatter{std::cerr, streamProvider, true, false}
	// 		.printErrorInformation(*errorList);
	// 	std::cerr << std::endl;
	// 	return 1;
	// }

	// yul::Block const& ast = get<phaser::Program>(maybeProgram).ast();
	// yul::AsmJsonConverter jsonConverter{{}};
	// std::cout << jsonConverter(ast) << std::endl;

	// string contractPath = argv[1];

	// langutil::ErrorList errors;
	// langutil::ErrorReporter errorReporter{errors};
	// frontend::Parser parser{errorReporter, langutil::EVMVersion()};

	// string contractContents = slurpFile(contractPath);
	// langutil::CharStream charStream{contractContents, contractPath};
	// auto sourceUnit = parser.parse(charStream);
	// ASTStatistics statistics{};
	// sourceUnit->accept(statistics);

	return 0;
}
