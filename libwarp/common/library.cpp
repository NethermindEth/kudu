#include "library.hpp"

#include <fstream>

bool contains_warp(std::vector<std::string> vec, std::string search) {
    auto it = std::find(vec.begin(), vec.end(), search);
    return it != vec.end();
}

std::vector<std::string> splitStr(const std::string& str) {
    std::vector<std::string> strings;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find('\n', prev)) != std::string::npos) {
        auto line = str.substr(prev, pos - prev);
        strings.push_back(line);
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    auto lastLine = str.substr(prev);
    strings.push_back(lastLine);

    return strings;
}

std::string slurpFile(std::string_view path) {
    constexpr size_t BUF_SIZE = 16384;

    std::string result;
    std::ifstream is{path.data()};
    is.exceptions(std::ifstream::badbit);
    std::string buf(BUF_SIZE, '\0');
    while (is.read(buf.data(), BUF_SIZE)) result.append(buf, 0, is.gcount());
    result.append(buf, 0, is.gcount());

    return result;
}

void writeFile(std::string filePath, std::string toWrite) {
    std::fstream file;
    file.open(filePath, std::ios::out | std::ios::trunc);
    file << toWrite;
    file.close();
}

void deleteFile(std::string filePath) {
    if (!std::remove(filePath.c_str()))
        return;
    else
        std::cout << "file " << filePath << " not found.\n";
}

std::string joinSrcSplit(std::vector<std::string> srcSplit) {
    std::string newSrc;
    std::for_each(srcSplit.begin(), srcSplit.end(),
                  [&newSrc](std::string line) { newSrc += line + "\n"; });
    return newSrc;
}

bool fileExists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
