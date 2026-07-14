#include "config.h"
#include <iostream>

namespace cpu
{
    
    static int clock{10};          // hidden inside config.cpp
    static bool debugMode{false};  // hidden inside config.cpp

    constexpr int defaultClock{10};
    constexpr bool defaultDebugMode{false};
    

    void printConfig()
    {
        std::cout << "\nCurrent configuration\n";
        std::cout << "Clock: " << clock << " MHz\n";

        if (debugMode)
            std::cout << "Debug mode: ON\n";
        else
            std::cout << "Debug mode: OFF\n";
    }

    void setClockFrequency()
    {
        std::cout << "\nEnter new clock: ";
        std::cin >> clock;

        std::cout << "\nConfiguration updated\n";
    }

    void toggleDebugMode()
    {
        debugMode = !debugMode;

        if (debugMode)
            std::cout << "\nDebug mode enabled\n";
        else
            std::cout << "\nDebug mode disabled\n";
    }

    void resetConfig()
    {
        clock = defaultClock;
        debugMode = defaultDebugMode;

        std::cout << "\nSettings reset to default\n";
    }
}