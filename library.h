#pragma once

#include "json.hpp"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/throw_exception.hpp>
#include <cassert>
#include <cctype>
#include <iostream>
#include <locale>
#include <set>
#include <sstream>
#include <vector>

using namespace std;
using json = nlohmann::json;

string slurpFile(string_view path)
{
	constexpr size_t BUF_SIZE = 4096;

	string result;
	ifstream is{path.data()};
	is.exceptions(ifstream::badbit);
	string buf(BUF_SIZE, '\0');
	while (is.read(buf.data(), BUF_SIZE))
		result.append(buf, 0, is.gcount());
	result.append(buf, 0, is.gcount());

	return result;
}

string exec(string cmdStr)
{
	const char* cmd = cmdStr.c_str();
	std::array<char, 4096> buffer;
	string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe)
	{
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	{
		result += buffer.data();
	}
	return result;
}



vector<string> getPublicFunchashes(size_t numberOfFuncs, const string& contract_path)
{
	std::ostringstream cmd;
	std::vector<string> hashes;
	hashes.reserve(numberOfFuncs);
	cmd << "solc --combined-json hashes " << contract_path;
	json res = json::parse(exec(cmd.str()));
	auto contracts = res["contracts"];
	for (auto contract: contracts)
	{
		for (auto hash: contract["hashes"].items())
		{
			hashes.emplace_back(hash.value());
		}
	}
	return hashes;
}
