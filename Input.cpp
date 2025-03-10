#include "input.h"
#include <iostream>
#include <string>
#include <cctype>
#include <string>
#include <unordered_map>
#include <stack>


//helper function to add parentheses
int precedence(char check) {
    if (check == '+' || check == '-') return 1;
    if (check == '*' || check == '/') return 2;
    return 0;
}


//assigns the value and makes all calculations
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


// string containing only digits
void Input::replaceUnkown(const std::unordered_map<char, double> &unknown)
{
    std::string a = "";
    for (char c : expression)
    {
        if (std::isalpha(c))
        {
            a = a + std::to_string(unknown.at(c)); 
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
    replaceUnkown(map);
}

void Input::AddWhiteSpace(int check, int insert){
    if(expression[check] != ' ' && check >= 0 && insert < expression.length())
    {
        expression.insert(insert, 1, ' ');
    }
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

    spaceBetweenOperators();
}

void Input::spaceBetweenOperators(){
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

