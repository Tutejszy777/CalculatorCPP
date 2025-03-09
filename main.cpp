#include <iostream>
#include "input.h"
#include "tree.h"


int main(int, char**){
    
    std::string expression;
    std::cout << "Enter a line of simple arithmetic or algebra expression: ";
    std::getline(std::cin, expression);

    Input input1(expression);
    expression = input1.result();

    ExpressionTree ex(expression);
    std::cout << "\n\n" << ex.Expression() << " = " << ex.Evaluate() << "\n\n" << std::endl;

    system("pause");
    return 0;
}
