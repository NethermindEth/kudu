#include "library.hpp"

#include <fstream>
#include <regex>

bool contains_warp(vector<string> vec, string search) {
    auto it = find(vec.begin(), vec.end(), search);
    return it != vec.end();
}

vector<string> splitStr(const string& str) {
    vector<string> strings;

    string::size_type pos = 0;
    string::size_type prev = 0;
    while ((pos = str.find('\n', prev)) != string::npos) {
        auto line = str.substr(prev, pos - prev);
        strings.push_back(line);
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    auto lastLine = str.substr(prev);
    strings.push_back(lastLine);

    return strings;
}

string slurpFile(string_view path) {
    constexpr size_t BUF_SIZE = 16384;

    string result;
    ifstream is{path.data()};
    is.exceptions(ifstream::badbit);
    string buf(BUF_SIZE, '\0');
    while (is.read(buf.data(), BUF_SIZE)) result.append(buf, 0, is.gcount());
    result.append(buf, 0, is.gcount());

    return result;
}

void writeFile(const string& filePath, const string& toWrite) {
    fstream file;
    file.open(filePath, ios::out | ios::trunc);
    file << toWrite;
    file.close();
}

void deleteFile(const string& filePath) {
    if (!remove(filePath.c_str()))
        return;
    else
        cout << "file " << filePath << " not found.\n";
}

bool fileExists(const string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

string joinSrcSplit(vector<string> srcSplit) {
    string newSrc;
    for_each(srcSplit.begin(), srcSplit.end(),
             [&newSrc](const string& line) { newSrc += line + "\n"; });
    return newSrc;
}

void replaceIdentifierName(string& srcString, const string& identifier,
                           string newIdentifier) {
    ostringstream regexStr;
    regexStr << "(\\b)" << identifier << "\\b";
    regex r(regexStr.str());
    string result = regex_replace(srcString, r, newIdentifier);
    srcString = result;
}

string removeEmptyLines(const string& str) {
    auto vecStr = splitStr(str);
    string newSrc;
    for_each(vecStr.begin(), vecStr.end(), [&newSrc](string line) {
        if (line.empty()) return;
        newSrc += line + "\n";
    });
    return newSrc;
}
