#include <boost/exception/diagnostic_information.hpp>
#include <boost/throw_exception.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string_view>
#include <variant>

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libyul/AST.h>
#include <libyul/AsmJsonConverter.h>
#include <solc/CommandLineInterface.h>
#include <tools/yulPhaser/Program.h>

using namespace solidity;

langutil::CharStream generateIR(char const* sol_filepath)
{
	std::istringstream sin; // never used, but the CLI requires it
	std::ostringstream sout;
	frontend::CommandLineInterface cli{sin, sout, std::cerr};
	constexpr int solc_argc = 4;
	char const* solc_argv[solc_argc] = {"irToJson", "--optimize", "--ir-optimized", sol_filepath};
	if (not cli.parseArguments(solc_argc, solc_argv))
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc CLI failed to parse arguments"});
	if (not cli.readInputFiles())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to read input files"});
	if (not cli.processInput())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to process input"});
	if (not cli.actOnInput())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to act on input"});

	std::string_view ir = sout.view();
	constexpr std::string_view IR_HEADER = "Optimized IR:";
	if (ir.substr(0, IR_HEADER.size()) != IR_HEADER)
	{
		std::ostringstream es;
		es << "Expected '" << IR_HEADER << "' header in solc IR output but not found" << std::endl;
		BOOST_THROW_EXCEPTION(std::runtime_error{es.str()});
	}
	ir.remove_prefix(IR_HEADER.size());

	return langutil::CharStream{ir.data(), "ir_stream"};
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "USAGE: " << argv[0] << " SOLIDITY-FILE" << std::endl;
		return 1;
	}
	char const* sol_filepath = argv[1];
	auto irStream = generateIR(sol_filepath);

	std::variant<phaser::Program, langutil::ErrorList> maybeProgram = phaser::Program::load(irStream);
	if (auto* errorList = std::get_if<langutil::ErrorList>(&maybeProgram))
	{
		langutil::SingletonCharStreamProvider streamProvider{irStream};
		langutil::SourceReferenceFormatter{std::cerr, streamProvider, true, false}
			.printErrorInformation(*errorList);
		std::cerr << std::endl;
		return 1;
	}

	yul::Block const& ast = get<phaser::Program>(maybeProgram).ast();
	yul::AsmJsonConverter jsonConverter{{}};
	std::cout << jsonConverter(ast) << std::endl;

	return 0;
}
