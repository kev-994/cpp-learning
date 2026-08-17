#include "PacketBuffer.h"
#include <iostream>

void printCapLen(const PacketBuffer& buffer)
{
    std::cout << "Capacity: " << buffer.capacity() << " Length: " << buffer.size() << '\n';
}

PacketBuffer createPacketBuffer(std::size_t capacity)
{
    return PacketBuffer {capacity};
}

int main()
{
    PacketBuffer buffer {2};

    printCapLen(buffer);

    buffer.append(1);
    printCapLen(buffer);

    buffer.append(2);
    printCapLen(buffer);

    buffer.append(3);
    printCapLen(buffer);

    buffer.append(4);
    printCapLen(buffer);
    buffer.append(5);
    printCapLen(buffer);
    buffer.print();

    buffer.clear();
    printCapLen(buffer);

    PacketBuffer otherBuffer {createPacketBuffer(1)};
    printCapLen(otherBuffer);

    return 0;
}