#include <solc/CommandLineInterface.h>

#include <string>

#include "yul-gen.h"

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
    try {
        return cli.run(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
    } catch (boost::exception const& _exception) {
        std::cerr << "Exception during output generation: "
                  << boost::diagnostic_information(_exception) << std::endl;
        return EXIT_FAILURE;
    } catch (std::exception const& _exception) {
        std::cerr << "Exception during output generation: " << _exception.what()
                  << std::endl;
        return EXIT_FAILURE;
    }
}

void printYulAST(std::string& main_contract, const char* sol_filepath) {
    try {
        std::string yul = generateYul(main_contract, sol_filepath);
        std::string yulJSON = generateYulJSON(yul, sol_filepath);
        std::cout << yulJSON << std::endl;
    } catch (std::exception const& exc) {
        std::cerr << "ERROR: " << exc.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 4 && std::string{argv[1]} == "--yul-json-ast") {
        char const* sol_filepath = argv[2];
        std::string main_contract = argv[3];
        printYulAST(main_contract, sol_filepath);
        return EXIT_SUCCESS;
    }
    return useNetherSolc(argc, argv);
}
