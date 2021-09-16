#pragma once
#include <boost/exception/diagnostic_information.hpp>
#include <boost/throw_exception.hpp>
#include <iostream>
#include <string>

#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolidity/interface/OptimiserSettings.h>
#include <libyul/AST.h>
#include <solc/CommandLineInterface.h>


using namespace solidity;
using namespace solidity::util;
using namespace solidity::langutil;
using namespace solidity::frontend;
using namespace std;


class StorageVars
{
public:
    StorageVars(const char* sol_filepath);
    frontend::CommandLineInterface getCli(char const* sol_filepath);
    vector<string> getStorageVars(const char* sol_filepath);
    vector<string> m_storageVars_str;
    vector<const VariableDeclaration*> m_storageVars_astNodes;
};