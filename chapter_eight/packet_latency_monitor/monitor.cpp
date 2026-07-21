#include "monitor.h"
#include "Random.h"
#include <iostream>

namespace
{
    unsigned int packetLatency{};
    unsigned int lowestLatency{50};
    unsigned int highestLatency{300};
    unsigned int minLatency{highestLatency}; // initialise latency bounds
    unsigned int maxLatency{lowestLatency};
    unsigned int slowPackets{};
    unsigned int slowPacketLatency{200};
    unsigned int packetNumber{1};
    unsigned int packetsProcessed{};
    unsigned int totalLatency{};
}

void checkMinLatency()
{
    if (packetLatency < minLatency)
        minLatency = packetLatency;
}

void checkMaxLatency()
{
    if (packetLatency > maxLatency)
        maxLatency = packetLatency;
}

bool checkSlowPacket()
{
    return packetLatency > slowPacketLatency;
}


bool consecutiveSlowPackets(bool isSlowPacket, unsigned int count)
{
    static unsigned int slowPacketsInARow{}; 

    if (isSlowPacket)
        ++slowPacketsInARow;
    else
        slowPacketsInARow = 0;

    
    return slowPacketsInARow == count;
}

bool processPacket()
{
    packetLatency = Random::get(lowestLatency, highestLatency);
    bool isSlowPacket{checkSlowPacket()};
    
    std::cout << "Packet #" << packetNumber++ << 
        ": " << packetLatency << " ns\n";

    ++packetsProcessed;
    totalLatency += packetLatency;
    checkMaxLatency();
    checkMinLatency();
    if (isSlowPacket)
        ++slowPackets;

    return isSlowPacket;
}

void printProcessingReport()
{
    std::cout << "----- Processing Report -----\n\n\n";
    std::cout << "Packets processed: " << packetsProcessed << '\n';
    std::cout << "Minimum latency: " << minLatency << " ns\n";
    std::cout << "Maximum latency: " << maxLatency << " ns\n";
    std::cout << "Average latency: " << totalLatency / packetsProcessed << " ns\n";
    std::cout << "Slow packets (>200 ns): " << slowPackets << '\n';
}



