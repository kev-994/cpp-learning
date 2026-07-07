#include <iostream>


int main()
{
    std::cout << "Enter total seconds: ";
    int totalSeconds{};
    std::cin >> totalSeconds;

    if (totalSeconds < 0)
    {
        std::cout << "Seconds cannot be negative\n";
        return 1;
    }

    constexpr int secondsPerMinute{ 60 };
    constexpr int secondsPerHour{ 60 * secondsPerMinute };

    int hours{totalSeconds / secondsPerHour};
    int minutes{(totalSeconds % secondsPerHour) / secondsPerMinute};
    int seconds{totalSeconds % secondsPerMinute};

    std::cout << totalSeconds << " seconds is " << hours << " hours, " << minutes << " minutes, and " 
              << seconds << " seconds.\n";

    return 0;
}