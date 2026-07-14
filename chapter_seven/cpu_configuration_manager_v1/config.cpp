#include "config.h"
#include <iostream>

namespace cpu // default settings stored in cpu namespace
{
    int clock{10}; // in MHZ
    bool debugMode{0}; // OFF
}   

void enable()
{
    std::cout << "\nDebug mode enabled\n";
}

void disable()
{
    std::cout << "\nDebug mode disabled\n";
}

void update()
{
    std::cout << "\nConfiguration updated\n";
}

void printConfig(int clock, bool debugMode)
{
    std::cout << "\nCurrent configuration\n";
    std::cout << "Clock: " << clock << " MHZ\n";

    if (debugMode)
    {
        std::cout << "Debug mode: " << "ON\n";
    }
    else
        std::cout << "Debug mode: " << "OFF\n";
}

int setClockFrequency()
{
    std::cout << "\nEnter new clock: ";
    int clock{};
    std::cin >> clock;
    update();

    return clock;
}

bool toggleDebugMode(bool debugMode)
{
    if (debugMode)
    {
        disable();
        return 0;
    }
    enable();
    return 1;
}

int resetClock()
{
    return cpu::clock;
}

bool resetDebugMode()
{
    return 0;
}

