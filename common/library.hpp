#pragma once

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <vector>


bool contains_warp(std::vector<std::string> vec, std::string search);

template <typename TType>
void print_vector(const std::vector<TType>& vec)
{
    typename  std::vector<TType>::const_iterator it;
    std::cout << "(";
    for(it = vec.begin(); it != vec.end(); it++)
    {
        if(it!= vec.begin()) std::cout << ",";
        std::cout << (*it);
    }
    std::cout << ")";
}

std::vector<std::string> splitStr(const std::string& str);