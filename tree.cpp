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

void AddWhiteSpace(int check, int insert, std::string& underEffect){
    if( check >= 0 && insert < underEffect.length() && underEffect[check] != ' ')
    {
        underEffect.insert(insert, 1, ' ');
    }
}

void PopOperator(std::stack<strng> &operatorStack, std:stack<Node*> &nodeStack){
    ExpressionTree::Node *n = new ExpressionTree::Node(operatorStack.top())
    operatorStack.pop();

    n->Right = nodeStack.top();
    nodeStack.pop();

    n->Left = nodeStack.top();
    nodeStack.pop();

    nodeStack.push(n);
}

void ExpressionTree::FromString(const std::string& strIn){
    std::string copy = strIn;
    for(char character : copy)
    {
        std::string temp;
        temp.push_back(character); //duoble check if passing char is valid method(to simplify)
        if(operators.find(temp) != operators.end())// if element present
        {
            AddWhiteSpace(i+1, i+1, copy);
            AddWhiteSpace(i-1, i, copy);
        }
    }

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
            else if(s == ")") 
            {
                while(operator){
                    PopOperator(operatorStack, nodeStack);
                }
            }
        }
    }
}