// counters.cpp
#include "counters.h"
#include <iostream>

namespace cpu
{
    namespace
    {
    unsigned int instructions{};
    unsigned int cacheHits{};
    unsigned int cacheMisses{};
    unsigned int branches{};
    unsigned int mispredictions{};
    }

    void recordInstruction()
    {
        ++instructions;
    }

    void recordCacheHit()
    {
        ++cacheHits;
    }

    void recordCacheMiss()
    {
        ++cacheMisses;
    }

    void recordBranch()
    {
        ++branches;
    }

    void recordMisprediction()
    {
        ++mispredictions;
        ++branches;
    }

    unsigned int reportNumber()
    {
        static unsigned int reportNumber{1};
        return reportNumber++;
    }

    void printPerformanceReport()
    {
        std::cout << "=== Performance Report #" << reportNumber() << " ===\n";
        std::cout << "Instructions: " << instructions << '\n';
        std::cout << "Cache hits: " << cacheHits << '\n';
        std::cout << "Cache misses: " << cacheMisses << '\n';
        if ((cacheHits + cacheMisses) == 0)
        {
            std::cout << "No cache accesses yet\n";
        }
        else
        {
            std::cout << "Cache hit rate: " << 100 * cacheHits / (cacheHits + cacheMisses) << "%\n";
        }
        std::cout << "Branches: " << branches << '\n';
        std::cout << "Branch mispredictions: " << mispredictions << '\n';
        if (branches == 0)
        {
            std::cout << "No branches yet\n";
        }
        else
        {
            std::cout << "Branch prediction accuracy: " << 100 * (branches - mispredictions) / branches << "%\n";
        }
    }    
    void resetCounters()
    {
        instructions = 0;
        cacheHits = 0;
        cacheMisses = 0;
        branches = 0;
        mispredictions = 0;

        std::cout << "Statistics reset.\n";
    }
}


