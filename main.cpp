#include <iostream>
#include "input.h"
#include "tree.h"


// INCOMPLETE VALIDATION for most cases as it's not mandatory
bool validationOfInput(std::string a)
{
    std::stack<char> par;
    std::string last = "";
    for(int i = 0; i < a.length(); i++){
        if(isspace(a[i])) continue;

        if( isdigit(a[i]) || a[i] == '.')
        {
            while(isdigit(a[i]) || a[i] == '.'){
                i++;
            }
            i--;
            if(last == "digit" || last == "x") return false;
            last = "digit";
        }
        else if( a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            if(last == "operator") return false;
            last = "operator";
        }
        else if(isalpha(a[i]))
        {
            if(last == "digit" || last == "x") return false;
            last = "x";
        }
        else if (a[i] == '(')
        {
            if(last == "digit" || last == "x" || last == "operator")
            par.push(a[i]);
        }
        else if (a[i] == ')')
        {
            if(!par.empty()){
                par.pop();
            }
            else return false;
        }
        else return false;
    }

    if(!par.empty()) return false;

    return true;
}

int main(int, char**){
    std::cout << "Example of valid input:  4*x + 5*( 2-1)-3\n";
    std::cout << "Enter a line of simple arithmetic or algebra expression: ";

    std::string expression;
    std::getline(std::cin, expression); // user enters the string 

    if(validationOfInput(expression))
    {
        Input input(expression); // passes the string to make into proper format for building a tree
        expression = input.result();

        //(VALIDATION IS NOT NEEDED IN THIS CASE BUT NICE TO HAVE)
        ExpressionTree tree(expression); // building a tree
        std::cout << "\n\n" << tree.Expression() << " = " << tree.Evaluate() << "\n\n" << std::endl; // evaluating
    }
    else std::cout << "INVALID INPUT\n\n";

    system("pause");
    return 0;
}
