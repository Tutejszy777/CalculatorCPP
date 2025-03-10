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

    void replaceUnkown(const std::unordered_map<char, double> &unknown); // string containing only digits
    void requestUnkown(); // fill the map with inserted values
    void addParentheses(); //adds parentheses for constructing tree
    void spaceBetweenOperators(); // adds spaces since I use stirng stream
    void AddWhiteSpace(int check, int isert);
};