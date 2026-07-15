/*
=== Performance Report #3 ===
Instructions: 1250
Cache hits: 420
Cache misses: 80
Cache hit rate: 84%
Branches: 200
Branch mispredictions: 12
Branch prediction accuracy: 94%
*/

#include <iostream>
#include "config.h"
#include "counters.h"


int main()
{

    std::cout << "CPU Performance Counter Simulator\n\n";
    std::cout << "1. Record instruction\n";
    std::cout << "2. Record cache hit\n";
    std::cout << "3. Record cache miss\n";
    std::cout << "4. Record branch\n";
    std::cout << "5. Record branch misprediction\n";
    std::cout << "6. Print statistics\n";
    std::cout << "7. Reset statistics\n";
    std::cout << "8. Exit\n";

    bool running{true};

    while (running)
    {
        std::cout << "\nChoose option: ";

        int option{};
        std::cin >> option;

        if (option == config::recordInstruction)
        {
            cpu::recordInstruction();
        }
        
        else if (option == config::recordCacheHit)
        {
            cpu::recordCacheHit();
        }
        
        else if (option == config::recordCacheMiss)
        {
            cpu::recordCacheMiss();
        }
        
        else if (option == config::recordBranch)
        {
            cpu::recordBranch();
        }
        
        else if (option == config::recordMisprediction)
        {
            cpu::recordMisprediction();
        }
        
        else if (option == config::printStatistics)
        {
            cpu::printPerformanceReport();
        }
        
        else if (option == config::resetStatistics)
        {
            cpu::resetCounters();
        }
        
        else if (option == config::exitProgram)
        {
            std::cout << "Exiting...\n";
            running = false;
        }

    }

    return 0;
}