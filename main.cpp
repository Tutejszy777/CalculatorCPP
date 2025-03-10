#include <iostream>
#include "input.h"
#include "tree.h"


int main(int, char**){
    
    std::cout << "Use Proper Format (4*x) NOT  (4x). REMEMBER TO USE MULTIPLICATION SIGN. \n";
    std::cout << "Enter a line of simple arithmetic or algebra expression: ";

    std::string expression;
    //(VALIDATION NEEDED but it wasn't a requirment)
    std::getline(std::cin, expression); // user enters the string 

    Input input1(expression); // passes the string to make into proper format for building a tree
    expression = input1.result();

    ExpressionTree ex(expression); // building a tree
    std::cout << "\n\n" << ex.Expression() << " = " << ex.Evaluate() << "\n\n" << std::endl; // evaluating

    system("pause");
    return 0;
}
