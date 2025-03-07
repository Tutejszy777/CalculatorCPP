#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <string>
#include <unordered_map>

class Input
{
public:
    Input(std::string s);
    
    std::string result();

private:
    std::string expression;

    void prepareString(const std::unordered_map<char, double> &unknown);
    void requestUnkown();
};