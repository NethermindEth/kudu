#pragma once

#include <sys/stat.h>

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool contains_warp(vector<string> vec, string search);
template <typename TType>
void print_vector(const vector<TType>& vec) {
    typename vector<TType>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << (*it) << endl;
    }
}
vector<string> splitStr(const string& str);
string slurpFile(string_view path);
void writeFile(const string& filePath, const string& toWrite);
void deleteFile(const string& filePath);
bool fileExists(const string& name);
string joinSrcSplit(vector<string> srcSplit);

void replaceIdentifierName(string& srcString, const string& identifier,
                           string newIdentifier);
string removeEmptyLines(const string& str);
