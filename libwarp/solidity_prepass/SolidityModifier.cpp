#include "SolidityModifier.hpp"

#include <boost/algorithm/string.hpp>

int getEndOfMultiLineComment(std::vector<std::string> lines, int start) {
    for (size_t i = start; i < lines.size(); i++) {
        boost::trim(lines[i]);
        if (boost::starts_with(lines[i], "*/")) return i;
    }
    throw std::runtime_error("Failed to find end of multi line comment.");
    return -1;
}

SolidityModifier& SolidityModifier::src(std::string src) {
    this->state.initSrc(src).initCLI().initCompiler().setCompilerOptions();
    return *this;
}

SolidityModifier& SolidityModifier::modifiedSolFilePath(
    std::string modifiedSolFilePath) {
    this->m_modifiedSolFilePath = modifiedSolFilePath;
    return *this;
}

SolidityModifier& SolidityModifier::removeComments() {
    std::vector<std::string> newSplit;
    int jump = 1;
    for (size_t i = 0; i < state.srcSplit.size(); i += jump) {
        if (i > state.srcSplit.size()) break;
        auto lineCopy = state.srcSplit[i];
        boost::trim(lineCopy);
        if (boost::starts_with(lineCopy, "//")) {
            jump = 1;
        } else if (boost::starts_with(lineCopy, "/*")) {
            if (lineCopy.find("*/") == std::string::npos) {
                auto end = getEndOfMultiLineComment(state.srcSplit, i);
                jump = end + 1 - (i);
                if (i + jump > state.srcSplit.size()) break;
            } else {
                jump = 1;
            }
        } else {
            jump = 1;
            newSplit.emplace_back(state.srcSplit[i]);
        }
    }
    std::string newSrc;
    std::for_each(newSplit.begin(), newSplit.end(),
                  [&newSrc](std::string line) { newSrc += line + "\n"; });
    this->state.srcSplit = newSplit;
    this->state.src = newSrc;
    return *this;
}

SolidityModifier& SolidityModifier::consolidateImports() {
    std::string consolidatedImports;
    for (const auto& [key, src] : state.cli->fileReader().sourceCodes()) {
        consolidatedImports += src;
    }
    auto vecStr = splitStr(consolidatedImports);
    for (auto it = vecStr.begin(); it != vecStr.end();) {
        if (it->find("import \'") != std::string::npos) {
            it = vecStr.erase(it);
        } else {
            ++it;
        }
    }
    state.src = joinSrcSplit(vecStr);
    state.srcOriginal = state.src;
    state.srcSplit = vecStr;
    return *this;
}
