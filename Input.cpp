#include "input.h"
#include <iostream>
#include <string>
#include <cctype>
#include <string>
#include <unordered_map>


Input::Input(std::string s) : expression(s)
{
    std::cout << "\nEntered line: " << expression << "\n";
    requestUnkown();
}

std::string Input::result()
{
    return expression;
}


void Input::prepareString(const std::unordered_map<char, double> &unknown)
{
    std::string a = "";
    for (char c : expression)
    {
        if (std::isalpha(c))
        {
            a = a + '(' + std::to_string(unknown.at(c)) + ')'; // quotes for 4x - case //test
        }
        else if (c == 32)
        {
            continue;
        }
        else
        {
            a += c;
        }
    }
    expression = a;
}


void Input::requestUnkown()
{
    std::unordered_map<char, double> map;
    std::cout << "NOTICE: non-digit value will be considered as 0\n";
    for (char c : expression)
    {
        if (std::isalpha(c) && map.find(c) == map.end())
        {
            double a;
            std::cout << "value of " << c << std::endl;
            std::cin >> a; // prevent user to enter non-digit
            map[c] = a;
        }
    }
    prepareString(map);
}
