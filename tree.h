#pragma once

#include <string>
#include <stack>
#include <map>

class ExpressionTree {
public:
    struct Node {
        Node(std::string v) : value(v), left(NULL), right(NULL) {}
        std::string value;
        Node *left, *right; 
    };

    ExpressionTree(const std::string& str);
    ~ExpressionTree();

    double Evaluate(Node* node = NULL) const;
    std::string Expression() const;

private:
    Node *root;
    std::string expression;
};