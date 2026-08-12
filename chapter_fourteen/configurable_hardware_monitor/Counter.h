#pragma once
#include <cstdint>

class Counter
{
public:
    Counter(std::uint32_t value = 0);
    
    void tick();
    std::uint32_t value() const;
private:
    std::uint32_t m_value {};
};
