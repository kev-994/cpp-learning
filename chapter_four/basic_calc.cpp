#include <iostream>

bool isOperator(char op)
{
    return '+' || '-' || '*' || '/';
}

double calculation(double x, double y, char op)
{
    if (op == '+')
    {
        return x + y;
    }
    else if (op == '-')
    {
        return x - y;
    }
    else if (op == '*')
    {
        return x * y;
    }
    else 
    {
        return x / y;
    }
}

int main()
{
    std::cout << "Enter a double: ";
    double x{};
    std::cin >> x;

    std::cout << "Enter a double: ";
    double y{};
    std::cin >> y;

    std::cout << "Enter +, -, * or /: ";
    char op{};
    std::cin >> op;

    if (isOperator(op))
    {
        std::cout << x << " " << op << " " << y << " is " << calculation(x, y, op); 
    }

    return 0;


}