#include <iostream>

int add(int a, int b)
{
    return a + b;
}
int multiply(int a, int b)
{
    return a * b;
}
int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    return base * power(base, exponent - 1);
}

int calculate(int a, int b, int (*calculatePtr)(int, int))
{
    return calculatePtr(a, b);
}

int main()
{
    std::cout << calculate(10, 7, &add) << '\n'; // can just write add as function names decay to function pointers
    std::cout << calculate(9, 12, &multiply) << '\n';
    std::cout << calculate(3, 4, &power) << '\n';

    return 0;
}