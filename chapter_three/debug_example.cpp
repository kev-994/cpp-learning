#include <iostream>

int add(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    int result{};
    x * y;
    return result;
}

double divide(int x, int y)
{
    return x / y;
}

void printResults(int x, int y)
{
    std::cout << "Sum: " << add(x, y) << '\n';
    std::cout << "Product: " << multiply(x, y) << '\n';
    std::cout << "Quotient: " << divide(x, y) << '\n';
}

int main()
{
    int a{};
    int b{};

    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    printResults(a, b);

    return 0;
}
