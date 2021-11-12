#pragma once
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/throw_exception.hpp>
#include <cassert>
#include <cctype>
#include <iostream>
#include <locale>
#include <set>
#include <vector>

#include "libwarp/common/json.hpp"
#include "libwarp/common/library.hpp"
using json = nlohmann::json;
using namespace std;

struct FinalizedYul {
    vector<string> onlyDefinitions;
    vector<string> entrySequence;
    int entrySeqEnd;
};

class YulCleaner {
   public:
    string cleanYul(string code, string& main_contract);

   private:
    vector<string> removePreamble(vector<string> lines);
    vector<string> getRuntimeYul(const vector<string>& yul);

    bool isRuntimeObj(string str);
    FinalizedYul removeDeploymentCode(vector<string> code);
    string addEntryFunc(vector<string> entrySeq, vector<string> cleanCode);
};
