#include <vector>
#include <iostream>
#include <cstdint>
#include <cassert>

namespace PacketField
{
    enum Field
    {
        VERSION,
        FLAGS,
        SOURCE,
        DESTINATION,
        LENGTH,
        numFields
    };
}


int main()
{
    std::vector<std::uint32_t> packet{0, 1, 2, 3, 4};
    assert(packet.size() == PacketField::numFields);

    packet[PacketField::SOURCE] = 994;
    std::uint32_t sum {};
    for (const auto& value : packet) sum += value;
    std::cout << "The sum of the values in the fields is " << sum << '\n';
}