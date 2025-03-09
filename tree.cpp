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
    if (node == NULL) node = root;

    operator_map::iterator it = operators.find(node->value); 
    if(it != operators.end()){
        return (it->second.Func)(Evaluate(node->left), Evaluate(node->right));
    }
    
    std::istringstream ss(node->value);
    double val;
    ss >> val;

    return val;
}

std::string ExpressionTree::Expression() const {
    return expression;
}

void PopOperator(std::stack<std::string> &operatorStack, std::stack<ExpressionTree::Node*> &nodeStack){
    ExpressionTree::Node *n = new ExpressionTree::Node(operatorStack.top());
    operatorStack.pop();

    n->right = nodeStack.top();
    nodeStack.pop();

    n->left = nodeStack.top();
    nodeStack.pop();

    nodeStack.push(n);
}

void ExpressionTree::FromString(const std::string& strIn){

    std::string copy = strIn;

    std::stack<Node*> nodeStack;
    std::stack<std::string> operatorStack;
    operatorStack.push("#");

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
            else if(temp == ")") {
                while(operatorStack.top() != "("){
                    PopOperator(operatorStack, nodeStack);
                }
                operatorStack.pop();
            }
            else if(operators[operatorStack.top()].Priority >= operators[temp].Priority){
                PopOperator(operatorStack, nodeStack);
                operatorStack.push(temp);
            }
            else {
                operatorStack.push(temp);
            }
        }
        else {
            Node *n = new Node(temp);
            nodeStack.push(n);
        }
    }

    while(operatorStack.top() != "#"){
        PopOperator(operatorStack, nodeStack);
    }

    root = nodeStack.top();
}