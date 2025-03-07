#include "blazor.h"
#include <iostream>



Value::Value(double val) : value(val) {}
        
double Value::calculate() const {
    return value;
}
        
void Value::print() const {
    std::cout << "Initial value: ";
    std::cout << "value" << std::endl;
}
