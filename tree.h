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

    static double Add(double x, double y) {return x + y;}
    static double Substract(double x, double y) {return x - y;}
    static double Multiply(double x, double y) {return x * y;}
    static double Divide(double x, double y) {return x / y;}


    //function pointer
    typedef double (*OperatorFunction)(double, double);
    // | inherits
    struct OperatorInfo {
        OperatorInfo() {}
        OperatorInfo(int i, OperatorFunction f) : Priority(i), Func(f) {}
        int Priority;
        OperatorFunction Func;
    };
    // | inherits
    typedef std::map<std::string, OperatorInfo> operator_map;
    void FromString(const std::string& str);

private:
    Node *root;
    std::string expression;

    static operator_map operators; // all trees share the same map
};