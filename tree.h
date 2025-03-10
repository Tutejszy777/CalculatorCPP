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

    ExpressionTree(const std::string& str); //constructor
    ~ExpressionTree(); //deconstructor

    void FromString(const std::string& str); // create a tree
    double Evaluate(Node* node = NULL) const; //solve the tree
    std::string Expression() const; // get passed expression


    // operations
    static double Add(double x, double y) {return x + y;}
    static double Substract(double x, double y) {return x - y;}
    static double Multiply(double x, double y) {return x * y;}
    static double Divide(double x, double y) {return x / y;}


    //function pointer to operation
    typedef double (*OperatorFunction)(double, double);
    // | added to struct, together with priority number
    struct OperatorInfo {
        OperatorInfo() {}
        OperatorInfo(int i, OperatorFunction f) : Priority(i), Func(f) {}
        int Priority;
        OperatorFunction Func;
    };
    // | map to convert operator to ceratain operation with precedence
    typedef std::map<std::string, OperatorInfo> operator_map;

private:
    std::string expression; // arrived string
    Node *root; // Pointer to a tree
    static operator_map operators; // all trees share the same map
};