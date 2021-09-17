#pragma once

#include "json.hpp"
#include <algorithm>
#include <sstream>
#include <vector>

using json = nlohmann::json;


std::vector<std::string> splitStr(const std::string& str)
{
	std::vector<std::string> strings;

	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while ((pos = str.find('\n', prev)) != std::string::npos)
	{
		strings.push_back(str.substr(prev, pos - prev));
		prev = pos + 1;
	}

	// To get the last substring (or only, if delimiter is not found)
	strings.push_back(str.substr(prev));

	return strings;
}

