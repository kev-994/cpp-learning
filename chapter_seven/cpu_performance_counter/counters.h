// counters.h

#ifndef COUNTERS_H
#define COUNTERS_H

 namespace cpu
{
    void recordInstruction();
    void recordCacheHit();
    void recordCacheMiss();
    void recordBranch();
    void recordMisprediction();

    void printPerformanceReport();

    void resetCounters();
}

#endif