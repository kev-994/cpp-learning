#include "PacketBuffer.h"
#include <iostream>

PacketBuffer::PacketBuffer(std::size_t capacity)
{
    m_buffer.reserve(capacity);
}

void PacketBuffer::append(std::uint32_t word)
{
    m_buffer.push_back(word);
}

void PacketBuffer::clear()
{
    m_buffer.clear();
}

std::size_t PacketBuffer::size() const
{
    return m_buffer.size();
}

std::size_t PacketBuffer::capacity() const
{
    return m_buffer.capacity();
}

void PacketBuffer::print() const
{
    for (const auto& word : m_buffer)
    {
        std::cout << word << ' ';
    }
    std::cout << '\n';
}

