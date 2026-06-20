#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;


    std::cout << "You entered " << x << '\n';

    return 0;
}

