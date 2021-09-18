#pragma once

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <vector>



std::vector<std::string> splitStr(const std::string& str)
{
	std::vector<std::string> strings;

	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while ((pos = str.find('\n', prev)) != std::string::npos)
	{
		auto line = str.substr(prev, pos - prev);
		strings.push_back(line);
		prev = pos + 1;
	}

	// To get the last substring (or only, if delimiter is not found)
	auto lastLine = str.substr(prev);
	strings.push_back(lastLine);

	return strings;
}
