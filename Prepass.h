#pragma once
#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
#include <cassert>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;


bool isRuntimeObj(string str)
{
    return ((str.find('{')) != string::npos) && 
        (str.find("object") != string::npos) && 
        (str.find("_deployed") != string::npos);
}

vector<string> removePreamble(vector<string> lines)
{
	for (size_t i = 0; i != lines.size(); ++i)	
	{
		if (lines[i].find("object") != string::npos)
		{
			return vector<string>(lines.begin() + i, lines.end());
		}
		else
		{
			continue;
		}
	}
	assert(0==1);
	return vector<string>();
}

vector<string> getRuntimeYul(vector<string> yul)
{
	vector<string> lines = removePreamble(yul);
	int start = lines[0].find("\"");
	int end = lines[0].find("\"", start + 1);
	string objectName = lines[0].substr(start, end - start);
	string deployedObjName = "object " + objectName + "_deployed";
	// replace(deployedObjName.begin(), deployedObjName.end(), '\"', '\0');
	trim_left(deployedObjName);
	trim_right(deployedObjName);

	for (size_t i = 0; i < lines.size(); i++)
	{
		string lineCopy = lines[i];
		// replace(lineCopy.begin(), lineCopy.end(), '\"', '\0');
        trim_left(lineCopy);
        trim_right(lineCopy);
		if (isRuntimeObj(lineCopy))
		{
            vector<string> runtimeObj = vector<string>(lines.begin() + i, lines.end());
            runtimeObj.insert(runtimeObj.begin(), lines[0]);
            return runtimeObj;
		}
	}
	return lines;
}

std::pair<vector<string>, vector<string>> removeDeploymentCode(vector<string> code)
{
	vector<string> cleanedCode;
	int start = 0;	
	for (size_t i = 1; i != code.size(); ++i)
	{
		string lineCopy = code[i];
        trim_left(lineCopy);
        trim_right(lineCopy);
		if (string(lineCopy.begin(), lineCopy.begin() + 8) == "function")
		{
			start = i;
			break;
		}
	}
	auto onlyDefinitions = vector<string>(code.begin() + start, code.end());
	auto entrySequence = vector<string>(code.begin() + 3, code.begin() + start);
	entrySequence.insert(entrySequence.begin(), std::string("\t\t\tfunction fun_ENTRY_POINT()"));
	onlyDefinitions.insert(onlyDefinitions.begin(), code.begin(), code.begin() + 3);
	return std::make_pair(onlyDefinitions,entrySequence);
}

vector<string> splitStr(const string& str)
{
	vector<string> strings;

	string::size_type pos = 0;
	string::size_type prev = 0;
	while ((pos = str.find('\n', prev)) != string::npos)
	{
		strings.push_back(str.substr(prev, pos - prev));
		prev = pos + 1;
	}

	// To get the last substring (or only, if delimiter is not found)
	strings.push_back(str.substr(prev));

	return strings;
}

vector<string> getEndOfOjbect(vector<string> lines)
{
	int end = 0;	
	for (size_t i = 0; i < lines.size(); i++)
	{
		string lineCopy = lines[i];
		trim_left(lineCopy);
		trim_right(lineCopy);
		if (lineCopy.find("Optimized IR") != string::npos)
		{
			end = i;
			break;
		}

	}
	if (end == 0)
	{
		return lines;
	}
	return vector<string>(lines.begin(), lines.begin() + end);

}

vector<string> getMainObject(string code, string& main_contract)
{
	trim_left(main_contract);
	trim_right(main_contract);
	std::transform(main_contract.begin(), main_contract.end(), main_contract.begin(),
		[](unsigned char c){ return std::tolower(c); });
	auto lines = splitStr(code);
	int start = 0;	
	for (size_t i = 0; i < lines.size(); i++)
	{
		string lineCopy = lines[i];
        trim_left(lineCopy);
        trim_right(lineCopy);
		std::transform(lineCopy.begin(), lineCopy.end(), lineCopy.begin(),
			[](unsigned char c){ return std::tolower(c); });
		if (lineCopy.find(main_contract) != string::npos)
		{
			start = int(i) - 1;
			break;
		}

	}
	auto res = vector<string>(lines.begin() + start , lines.end());
	return getEndOfOjbect(res);
}

string addEntryFunc(vector<string> entrySeq, vector<string> cleanCode)
{
	string entryStr;
	// So we can look ahead by 2 and still make
	// sure we read all the generated Yul.
	cleanCode.push_back("\n");
	cleanCode.push_back("\n");
	string yulStr;
	for (auto line : entrySeq)
	{
		entryStr += line + "\n";
	}		
	for (auto i = 0; i < cleanCode.size() - 2; i++) 
	{
		yulStr += cleanCode[i] + "\n";
		if (cleanCode[i+2].find("data \".metadata\" hex\"") != string::npos)
		{
			yulStr += entryStr + "\n";
		}		
	}
	return yulStr;
}
string cleanYul(string code, string& main_contract)
{
	auto yul = getMainObject(code, main_contract);
	auto runtimeYul = getRuntimeYul(yul);
	vector<string> clean;
	vector<string> entry;
	std::tie(clean, entry) = removeDeploymentCode(runtimeYul);
	auto placeHolder = "\tcode {\n\t\t//holder\n\t}\n";
	clean.insert(clean.begin()+ 1 , placeHolder);
	auto complete = addEntryFunc(entry, clean);
	return complete;
}