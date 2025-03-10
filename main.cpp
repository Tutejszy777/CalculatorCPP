#include <iostream>
#include "input.h"
#include "tree.h"


int main(int, char**){
    
    std::cout << "Use Proper Format (4*x) NOT  (4x). REMEMBER TO USE MULTIPLICATION SIGN. \n";
    std::cout << "Enter a line of simple arithmetic or algebra expression: ";

    std::string expression;
    //(VALIDATION NEEDED but it wasn't a requirment)
    std::getline(std::cin, expression); // user enters the string 

    Input input(expression); // passes the string to make into proper format for building a tree
    expression = input.result();

    //(VALIDATION IS NOT NEEDED IN THIS CASE BUT NICE TO HAVE)
    ExpressionTree tree(expression); // building a tree
    std::cout << "\n\n" << tree.Expression() << " = " << tree.Evaluate() << "\n\n" << std::endl; // evaluating

    system("pause");
    return 0;
}
