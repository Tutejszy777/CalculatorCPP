#include <iostream>
#include "input.h"

int main(int, char**){
    
    std::string expression;
    std::cout << "Enter a line of simple arithmetic or algebra expression: ";
    std::getline(std::cin, expression);

    Input input1(expression);

    expression = input1.result();
    std::cout << "Intermediate string: " << expression;

    std::cin >> expression;

    return 0;
}
