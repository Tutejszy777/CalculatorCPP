#include <iostream>
#include <string>
#include <cctype>
#include <string>
#include <unordered_map>

class Input
{
public:
    Input(std::string s) : expression(s)
    {
        std::cout << "\nEntered line: " << expression << "\n";
        requestUnkown();
    }

    std::string result()
    {
        return expression;
    }

private:
    std::string expression;

    void prepareString(const std::unordered_map<char, double> &unknown)
    {
        std::string a = "";

        for (char c : expression)
        {
            if (std::isalpha(c))
            {
                a = a + '(' + std::to_string(unknown.at(c)) + ')'; // quotes for 4x - case //test
            }
            else if (c == 32)
            {
                continue;
            }
            else
            {
                a += c;
            }
        }

        expression = a;
    }

    void requestUnkown()
    {
        std::unordered_map<char, double> map;
        std::cout << "NOTICE: non-digit value will be considered as 0\n";

        for (char c : expression)
        {
            if (std::isalpha(c) && map.find(c) == map.end())
            {
                double a;
                std::cout << "value of " << c << std::endl;
                std::cin >> a; // prevent user to enter non-digit
                map[c] = a;
            }
        }

        prepareString(map);
    }
};

int main()
{

    std::string expression;
    std::cout << "Enter a line of simple arithmetic or algebra expression: ";
    std::getline(std::cin, expression);

    Input input1(expression);

    expression = input1.result();
    std::cout << "Intermediate string: " << expression;

    return 0;
}