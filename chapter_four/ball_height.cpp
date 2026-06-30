#include <iostream>

double getHeight(double height, double x_seconds)
{
    double g{9.81};
    double currentHeight{height - g * x_seconds*x_seconds / 2};
    
    if (currentHeight <= 0)
        return 0;
    else
        return currentHeight;
}

void printHeight(double height, double x)
{
    if (getHeight(height, x) != 0)
        std::cout << "At " << x << " seconds, the ball is at height: " << getHeight(height, x) << " meters\n";
    else
        std::cout << "At " << x << " seconds, the ball is on the ground\n";
}


int main()
{
    std::cout << "Enter the height of the tower in metres: ";
    double height{};
    std::cin >> height;

    printHeight(height, 0);
    printHeight(height, 1);
    printHeight(height, 2);
    printHeight(height, 3);
    printHeight(height, 4);
    printHeight(height, 5);

    return 0;


}