#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <string>
#include <unordered_map>

class Input
{
public:
    Input(std::string s); //constructor
    
    std::string result(); //access the string

private:
    std::string expression; // string to work with

    void prepareString(const std::unordered_map<char, double> &unknown); // string containing only digits and NO-WHITESPACES
    void requestUnkown(); // fill the map with inserted values
    void AddWhiteSpace(int check, int isert);
};