#include "input.h"
#include <iostream>
#include <string>
#include <cctype>
#include <string>
#include <unordered_map>
#include <stack>

//result
Input::Input(std::string s) : expression(s)
{
    requestUnkown();
    addParentheses();
}

//retrieve expression
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
}

// fill the map with inserted values
void Input::requestUnkown()
{
    std::unordered_map<char, double> map;
    std::cout << "\nNOTICE: non-digit value will be considered as 0\n";
    for (char c : expression)
    {
        if (std::isalpha(c) && map.find(c) == map.end())
        {
            double a;
            std::cout << "Enter value of " << c << " " << std::endl;
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

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void Input::addParentheses() {
    std::stack<std::string> values;
    std::stack<char> ops;

    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            std::string num;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                num += expression[i];
                i++;
            }
            i--;
            values.push(num);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                std::string right = values.top(); values.pop();
                std::string left = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push("(" + left + " " + op + " " + right + ")");
            }
            ops.pop();
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                std::string right = values.top(); values.pop();
                std::string left = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push("(" + left + " " + op + " " + right + ")");
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        std::string right = values.top(); values.pop();
        std::string left = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push("(" + left + " " + op + " " + right + ")");
    }


    expression = values.top();

    //whitespaces
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

