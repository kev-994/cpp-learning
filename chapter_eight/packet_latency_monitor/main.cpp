#include "monitor.h"
#include <iostream>

int main()
{
    unsigned int packetsToProcess{100};
    unsigned int maxSlowPackets{5};


    for (unsigned int i{}; i<packetsToProcess; ++i)
    {
        bool isSlowPacket{processPacket()};;
        
        if (consecutiveSlowPackets(isSlowPacket, maxSlowPackets))
        {
            std::cout << "ALERT: Excessive latency detected.\n\n";
            break;
        }
    }
    printProcessingReport();

    return 0;
}
