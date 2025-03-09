#include "tree.h"

#include <string>
#include <stack>
#include <map>
#include <sstream>

ExpressionTree::operator_map ExpressionTree::operators; //specific isntance to use

ExpressionTree::ExpressionTree(const std::string& str) : expression(str) {
    if(operators.empty()){
        operators["+"] = ExpressionTree::OperatorInfo(0, ExpressionTree::Add);
        operators["-"] = ExpressionTree::OperatorInfo(0, ExpressionTree::Substract);
        operators["*"] = ExpressionTree::OperatorInfo(1, ExpressionTree::Multiply);
        operators["/"] = ExpressionTree::OperatorInfo(1, ExpressionTree::Divide);
        operators["("] = ExpressionTree::OperatorInfo(-1, NULL);
        operators[")"] = ExpressionTree::OperatorInfo(-1, NULL);
        operators["#"] = ExpressionTree::OperatorInfo(-1, NULL); //special char for stack
    }//thread unsafe


}
ExpressionTree::~ExpressionTree() {}

double ExpressionTree::Evaluate(Node* node = NULL) const {
    return 0;
}

std::string ExpressionTree::Expression() const {
    return expression;
}

void ExpressionTree::FromString(const std::string& strIn){

    std::stack<std::string> operatorStack;
    operatorStack.push("#");

    std::stack<Node*> nodeStack;

    std::istringstream ss(copy);
    while(!ss.eof())
    {
        std::string temp;
        ss >> temp;

        if(operators.find(temp) != operators.end())
        {
            if(temp == "("){
                operatorStack.push(temp);
            }
        }
    }
}