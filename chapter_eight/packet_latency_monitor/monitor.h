#ifndef MONITOR_H
#define MONITOR_H

bool processPacket();
void printProcessingReport();
bool consecutiveSlowPackets(bool isSlowPacket, unsigned int count);

#endif