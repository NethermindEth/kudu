#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libyul/AST.h>
#include <libyul/AsmJsonConverter.h>
#include <solc/CommandLineInterface.h>
#include <tools/yulPhaser/Program.h>

#include "yul_prepass/Prepass.hpp"
#include "solidity_prepass/WarpVisitor.hpp"

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

solidity::langutil::CharStream generateIR(char const* sol_filepath)
{
	std::string yulOptimiserSteps
		= solidity::frontend::OptimiserSettings::DefaultYulOptimiserSteps;
	erase(yulOptimiserSteps, 'i'); // remove FullInliner
	yulOptimiserSteps += " x";	   // that flattens function calls: only one
								   // function call per statement is allowed
	constexpr int solc_argc			   = 6;
	char const*	  solc_argv[solc_argc] = {
		  "irToJson",
		  "--optimize",
		  "--ir-optimized",
		  "--yul-optimizations",
		  yulOptimiserSteps.c_str(),
		  sol_filepath,
	  };

	std::istringstream						 sin; // never used, but the CLI requires it
	std::ostringstream						 sout;
	solidity::frontend::CommandLineInterface cli{sin, sout, std::cerr};
	if (not cli.parseArguments(solc_argc, solc_argv))
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc CLI failed to parse arguments"});
	if (not cli.readInputFiles())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to read input files"});
	if (not cli.processInput())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to process input"});
	if (not cli.actOnInput())
		BOOST_THROW_EXCEPTION(std::runtime_error{"solc failed to act on input"});

	std::string_view		   ir		 = sout.view();
	constexpr std::string_view IR_HEADER = "Optimized IR:";
	if (ir.substr(0, IR_HEADER.size()) != IR_HEADER)
	{
		std::ostringstream es;
		es << "Expected '" << IR_HEADER << "' header in solc IR output but not found"
		   << std::endl;
		BOOST_THROW_EXCEPTION(std::runtime_error{es.str()});
	}
	ir.remove_prefix(IR_HEADER.size());

	return solidity::langutil::CharStream{ir.data(), "ir_stream"};
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

	char const* sol_filepath	 = argv[1];
	std::string main_contract	 = argv[2];
	std::string contractContents = slurpFile(sol_filepath);

	// =============== Solidity pre-pass ===============
	solidity::langutil::CharStream	  charStream{contractContents, sol_filepath};
	solidity::langutil::ErrorList	  errors;
	solidity::langutil::ErrorReporter errorReporter{errors};
	solidity::frontend::Parser parser{errorReporter, solidity::langutil::EVMVersion()};

	auto		sourceUnit = parser.parse(charStream);
	SourceData sourceData(main_contract, contractContents, sol_filepath);
	sourceData.m_srcSplit = splitStr(sourceData.m_src);
	sourceData.compressSigs();
	sourceData.setSourceData(sourceData.m_filepath.c_str());
	// sourceUnit->accept(sourceData);
	// warpVisitor.writeModifiedSolidity();

	// solidity::langutil::CharStream irStream;
	// try
	// {
	// 	irStream = generateIR(warpVisitor.m_modifiedSolFilepath.c_str());
	// }
	// catch (boost::exception const& exc)
	// {
	// 	std::cerr << boost::diagnostic_information(exc) << std::endl;
	// 	return 1;
	// }

	// // =============== Yul pre-pass ===============
	// auto		prepass	 = Prepass(warpVisitor.m_src, main_contract, warpVisitor.m_modifiedSolFilepath.c_str());
	// std::string irSource = irStream.source();
	// auto		yul		 = prepass.cleanYul(irSource, main_contract);

	// // =============== Generate Yul JSON AST ===============
	// solidity::langutil::CharStream ir = solidity::langutil::CharStream(yul, sol_filepath);
	// std::variant<solidity::phaser::Program, solidity::langutil::ErrorList> maybeProgram
	// 	= solidity::phaser::Program::load(ir);
	// if (auto* errorList = std::get_if<solidity::langutil::ErrorList>(&maybeProgram))
	// {
	// 	solidity::langutil::SingletonCharStreamProvider streamProvider{ir};
	// 	solidity::langutil::
	// 		SourceReferenceFormatter{std::cerr, streamProvider, true, false}
	// 			.printErrorInformation(*errorList);
	// 	std::cerr << std::endl;
	// 	return 1;
	// }

	// solidity::yul::Block const& ast = get<solidity::phaser::Program>(maybeProgram).ast();
	// solidity::yul::AsmJsonConverter jsonConverter{{}};
	// std::cout << jsonConverter(ast) << std::endl;

	return 0;
}
