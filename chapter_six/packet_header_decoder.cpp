// 32-bit packet header decoder
/*
Bits 31–28: version
Bits 27–24: packet type
Bits 23–16: source ID
Bits 15–8 : destination ID
Bits 7–4  : flags
Bits 3–0  : checksum
*/

#include <iostream>

bool validPacket(unsigned int version, unsigned int packetType, unsigned int sourceID, 
    unsigned int destinationID, unsigned int flags, unsigned int checksum)
{
    if (!(version >= 1 && version <= 4))
        return false;
    
    if (packetType == 0)
        return false;
    
    if (sourceID == destinationID)
        return false;
    
    unsigned int expectedChecksum{(version + packetType + sourceID + destinationID + flags) & 0xF};
    if (checksum != expectedChecksum)
        return false;
    
    return true;
    
}

int main()
{
    std::cout << "Enter packet header: ";
    unsigned int packet{};
    std::cin >> packet;

    unsigned int version{(packet >> 28) & 0xF};
    unsigned int packetType{(packet >> 24) & 0xF};
    unsigned int sourceID{(packet >> 16) & 0xFF};
    unsigned int destinationID{(packet >> 8) & 0xFF};
    unsigned int flags{(packet >> 4) & 0xF};
    unsigned int checksum{packet & 0xF};

    std::cout << "\nDecoded packet:\n";
    std::cout << "Version: " << version << '\n';
    std::cout << "Packet type: " << packetType << '\n';
    std::cout << "Source ID: " << sourceID << '\n';
    std::cout << "Destination ID: " << destinationID << '\n';
    std::cout << "Flags: " << flags << '\n';
    std::cout << "Checksum: " << checksum << "\n\n";

    std::cout << "Packet is " << (validPacket(version, packetType, sourceID, 
        destinationID, flags, checksum) ? "valid" : "invalid") << '\n';

    return 0;

}