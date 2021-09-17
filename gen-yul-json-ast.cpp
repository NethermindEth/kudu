#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include <liblangutil/CharStreamProvider.h>
#include <libyul/AST.h>
#include <libyul/AsmJsonConverter.h>
#include <solc/CommandLineInterface.h>
#include <tools/yulPhaser/Program.h>

// #include "Prepass.hpp"
#include "WarpVisitor.hpp"


std::vector<std::string> splitStr(const std::string& str);

std::string slurpFile(std::string_view path)
{
	constexpr size_t BUF_SIZE = 4096;

	std::string	  result;
	std::ifstream is{path.data()};
	is.exceptions(std::ifstream::badbit);
	std::string buf(BUF_SIZE, '\0');
	while (is.read(buf.data(), BUF_SIZE))
		result.append(buf, 0, is.gcount());
	result.append(buf, 0, is.gcount());

	return result;
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "USAGE: " << argv[0] << " SOLIDITY-FILE "
				  << "MAIN-CONTRACT-NAME" << std::endl;
		std::cerr << "Where MAIN-CONTRACT-NAME is the name of the primary contract "
					 "(non-interface,  non-library, non-abstract contract)"
				  << std::endl;
		return 1;
	}
	char const* sol_filepath  = argv[1];
	std::string sol_src		  = slurpFile(sol_filepath);
	std::string main_contract = argv[2];

	// auto prepass = Prepass(sol_src, main_contract, sol_filepath);
	// prepass.tester();

	solidity::langutil::ErrorList	  errors;
	solidity::langutil::ErrorReporter errorReporter{errors};
	solidity::frontend::Parser parser{errorReporter, solidity::langutil::EVMVersion()};


	std::string					   contractContents = slurpFile(sol_filepath);
	solidity::langutil::CharStream charStream{contractContents, sol_filepath};
	auto						   sourceUnit = parser.parse(charStream);

	WarpVisitor funcVisitor(main_contract, contractContents, sol_filepath);
	sourceUnit->accept(funcVisitor);
	funcVisitor.removeDuplicates();
	funcVisitor.getDynFunctions();
	funcVisitor.markDynFunctions();
	for (auto i : funcVisitor.m_publicFunctions.sigs)
	{
		std::cout << i << std::endl;
	}
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
