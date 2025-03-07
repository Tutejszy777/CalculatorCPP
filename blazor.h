#pragma once

class INode{
public:
    virtual double calculate() const = 0;
    virtual void print() const = 0;
    virtual ~INode() = default;
};

class Value : public INode {
private:
    double value;
public:
    Value(double val);
    double calculate() const override;
    void print() const override;
};