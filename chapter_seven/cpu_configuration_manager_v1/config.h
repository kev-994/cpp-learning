#ifndef CONFIG_H
#define CONFIG_H

namespace cpu // default settings stored in cpu namespace
{
    extern int  clock;
    extern bool debugMode;
}   
void printConfig(int clock, bool debugMode);

int setClockFrequency();

bool toggleDebugMode(bool debugMode);

void enable();
void disable();

void update();

int resetClock();
bool resetDebugMode();


#endif
