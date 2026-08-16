#include <vector>
#include <cstdint>
#include <iostream>

std::vector<std::uint32_t> createPacket(std::size_t wordCount)
{
    std::vector<std::uint32_t> packet(wordCount);

    for (std::size_t i{}; i < wordCount; ++i)
    {
        packet[i] = i*10;
    }
    return packet;
}

void printPacket(const std::vector<std::uint32_t>& packet)
{
    std::size_t length {packet.size()};
    std::cout << '[';
    for (std::size_t i{}; i < length; ++i)
    {
        std::cout << packet[i];
        if (i != length-1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main()
{
    std::cout << "Enter word count: ";
    std::size_t wordCount {};
    std::cin >> wordCount;

    auto packet {createPacket(wordCount)};
    printPacket(packet);
}