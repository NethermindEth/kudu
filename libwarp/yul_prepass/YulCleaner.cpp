#include "YulCleaner.hpp"

#include <libyul/Utilities.h>

using namespace boost;

bool YulCleaner::isRuntimeObj(string str) {
    return ((str.find('{')) != string::npos) &&
           (str.find("object") != string::npos) &&
           (str.find("_deployed") != string::npos);
}

vector<string> YulCleaner::removePreamble(vector<string> lines) {
    for (size_t i = 0; i != lines.size(); ++i) {
        if (lines[i].find("object") != string::npos) {
            return vector<string>(lines.begin() + i, lines.end());
        } else {
            continue;
        }
    }
    assert(0 == 1);
    return vector<string>();
}

vector<string> YulCleaner::getRuntimeYul(const vector<string>& yul) {
    vector<string> lines = removePreamble(yul);
    int start = lines[0].find("\"");
    int end = lines[0].find("\"", start + 1);
    string objectName = lines[0].substr(start, end - start);
    string deployedObjName = "object " + objectName + "_deployed";
    trim(deployedObjName);

    for (size_t i = 0; i < lines.size(); i++) {
        string lineCopy = lines[i];
        trim(lineCopy);
        if (isRuntimeObj(lineCopy)) {
            vector<string> runtimeObj =
                vector<string>(lines.begin() + i, lines.end());
            runtimeObj.insert(runtimeObj.begin(), lines[0]);
            return runtimeObj;
        }
    }
    return lines;
}

FinalizedYul YulCleaner::removeDeploymentCode(vector<string> code) {
    int start = 0;
    for (size_t i = 1; i != code.size(); ++i) {
        string lineCopy = code[i];
        trim(lineCopy);
        if (string(lineCopy.begin(), lineCopy.begin() + 8) == "function") {
            start = i;
            break;
        }
    }
    auto onlyDefinitions = vector<string>(code.begin() + start, code.end());
    auto entrySequence =
        vector<string>(code.begin() + 3, code.begin() + start - 2);
    entrySequence.emplace_back("}");
    int entrySeqEnd = std::distance(code.begin() + 3, code.begin() + start);
    entrySequence.insert(entrySequence.begin(),
                         string("\t\t\tfunction fun_ENTRY_POINT()"));
    onlyDefinitions.insert(onlyDefinitions.begin(), code.begin(),
                           code.begin() + 3);
    return FinalizedYul{onlyDefinitions, entrySequence, entrySeqEnd};
}

string YulCleaner::addEntryFunc(vector<string> entrySeq,
                                vector<string> cleanCode) {
    string yulStr;
    string entryStr = joinSrcSplit(entrySeq);
    auto it = find(cleanCode.begin(), cleanCode.end(), "        code {");
    cleanCode.insert(it + 1, entryStr);
    return joinSrcSplit(cleanCode);
}

string YulCleaner::cleanYul(string code, string& main_contract) {
    auto runtimeYul = getRuntimeYul(splitStr(code));
    vector<string> clean;
    vector<string> entry;
    FinalizedYul finalYul = removeDeploymentCode(runtimeYul);
    clean = finalYul.onlyDefinitions;
    entry = finalYul.entrySequence;
    auto placeHolder = "\tcode {\n\t\t//holder\n\t}\n";
    clean.insert(clean.begin() + 1, placeHolder);
    auto complete = addEntryFunc(entry, clean);
    return complete;
}
