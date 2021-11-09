#include <libsolidity/interface/FileReader.h>
#include <solc/CommandLineInterface.h>

#include "libwarp/solidity_prepass/SolidityModifierState.hpp"

using namespace solidity::frontend;

class SolidityModifier {
   public:
    std::string solFilePath() { return m_solFilePath; };
    std::string modifiedSolFilePath() { return m_modifiedSolFilePath; };

    SolidityModifier& src(std::string src);
    SolidityModifier& modifiedSolFilePath(std::string modifiedSolFilePath);
    SolidityModifier& consolidateImports();
    SolidityModifier& removeComments();
    SolidityModifier& writeModifiedSolidity() {
        writeFile(m_modifiedSolFilePath, state.src);
        return *this;
    }
    SolidityModifier& compilerStack(ReadCallback::Callback reader);

    SolidityModifierState state;
    std::string m_solFilePath;
    std::string m_modifiedSolFilePath;
};
