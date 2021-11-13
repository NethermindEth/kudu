#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libyul/AST.h>
#include <libyul/AsmJsonConverter.h>
#include <solc/CommandLineInterface.h>
#include <tools/yulPhaser/Program.h>

#include <boost/exception/all.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "libwarp/solidity_prepass/WarpVisitor.hpp"
#include "libwarp/yul_prepass/YulCleaner.hpp"

std::vector<std::string> splitStr(const std::string& str);

static void setDefaultOrCLocale() {
#if __unix__
    if (!std::setlocale(LC_ALL, "")) {
        setenv("LC_ALL", "C", 1);
    }
#endif
}

int useNetherSolc(int argc, char* argv[]) {
    setDefaultOrCLocale();
    solidity::frontend::CommandLineInterface cli(std::cin, std::cout,
                                                 std::cerr);
    if (!cli.parseArguments(argc, argv)) return 1;
    if (!cli.readInputFiles()) return 1;
    if (!cli.processInput()) return 1;
    bool success = false;
    try {
        success = cli.actOnInput();
    } catch (boost::exception const& _exception) {
        std::cerr << "Exception during output generation: "
                  << boost::diagnostic_information(_exception) << std::endl;
        success = false;
    }
    return success ? 0 : 1;
}

int printUsageInfo(char* argv[]) {
    std::cerr << "USAGE: " << argv[0] << " --yul-json-ast SOLIDITY-FILE "
              << "MAIN-CONTRACT-NAME" << std::endl;
    std::cerr << "Where MAIN-CONTRACT-NAME is the name of the primary contract "
                 "(non-interface,  non-library, non-abstract contract)"
              << std::endl;
    return 1;
}

void printYulAST(std::string& main_contract, std::string& contractContents,
                 const char* sol_filepath, bool print_ir) {
    try {
        WarpVisitor warpVisitor(main_contract, contractContents, sol_filepath,
                                print_ir);
        warpVisitor.yulPrepass().yulPass().generateYulAST();
        std::cout << warpVisitor.m_yul_JSON_AST << std::endl;
    } catch (std::exception const& exc) {
        std::cerr << "ERROR: " << exc.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 5) {
        return printUsageInfo(argv);
    }
    if (std::string(argv[1]) != "--yul-json-ast") {
        return useNetherSolc(argc, argv);
    }
    char const* sol_filepath = argv[2];
    std::string main_contract = argv[3];
    bool print_ir =
        argc == 5 ? std::strncmp(argv[4], "--print-ir", 10) == 0 : false;
    std::string contractContents = slurpFile(sol_filepath);
    printYulAST(main_contract, contractContents, sol_filepath, print_ir);
    if (fileExists("YUL_PASS")) deleteFile("YUL_PASS");
    return 0;
}
