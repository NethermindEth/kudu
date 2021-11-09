#pragma once
#include <libsolidity/interface/FileReader.h>
#include <solc/CommandLineInterface.h>

#include <string>
#include <vector>

#include "libwarp/common/library.hpp"

using namespace solidity::frontend;

struct SolidityModifierState {
    SolidityModifierState& initSrc(std::string _src);
    SolidityModifierState& initCLI();
    SolidityModifierState& initCompiler();
    SolidityModifierState& setCompilerOptions();
    SolidityModifierState& refresh();

    std::string yulOptimizerSteps();

    std::unique_ptr<CommandLineInterface> cli;
    std::shared_ptr<CompilerStack> compiler;
    std::vector<std::string> contractNames;
    std::vector<std::string> interfaceNames;
    std::map<std::string, std::vector<std::string>> interfaces;

    std::vector<FunctionDefinition const*> definedFunctions;
    std::vector<std::string> storageVars_str;
    std::string src;
    std::string srcOriginal;
    std::string modifiedSolFilePath;
    OptimiserSettings optimizerSettings;
    std::vector<std::string> srcSplit;
};
