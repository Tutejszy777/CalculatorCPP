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


// string containing only digits and NO-WHITESPACES
void Input::prepareString(const std::unordered_map<char, double> &unknown)
{
    std::string a = "";
    for (char c : expression)
    {
        if (std::isalpha(c))
        {
            a = a + std::to_string(unknown.at(c)); // quotes for 4x - case //test
        }
        else
        {
            a += c;
        }
    }
    expression = a;

    int i = 0;
    while(i < expression.length()) 
    {
        if(expression[i] == '(' || expression[i] == ')' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' )
        {
            AddWhiteSpace(i + 1, i + 1);
            AddWhiteSpace(i - 1, i);
        }
        i++;
    }
}


// fill the map with inserted values
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

void Input::AddWhiteSpace(int check, int insert){
    if(expression[check] != ' ' && check >= 0 && insert < expression.length())
    {
        expression.insert(insert, 1, ' ');
    }
}
