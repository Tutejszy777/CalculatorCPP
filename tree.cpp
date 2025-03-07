#include "tree.h"

#include <string>
#include <stack>
#include <map>


ExpressionTree::ExpressionTree(const std::string& str) : expression(str) {}
ExpressionTree::~ExpressionTree() {}

duoble ExpressionTree::Evaluate(Node* node = NULL) const {
    return 0;
}
std::string ExpressionTree::Expression() const {
    return expression;
}