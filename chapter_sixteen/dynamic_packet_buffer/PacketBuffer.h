#pragma once

#include <cstdint>
#include <vector>


class PacketBuffer
{
public:
    explicit PacketBuffer(std::size_t capacity);

    void append(std::uint32_t word);
    void clear();

    std::size_t size() const;
    std::size_t capacity() const;

    void print() const;

private:
    std::vector<std::uint32_t> m_buffer;
};
