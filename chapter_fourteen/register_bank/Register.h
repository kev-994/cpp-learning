#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <optional>

class Register
{
public:
    Register(std::uint32_t address, const std::string& name, bool readable, bool writeable);

    std::optional<std::uint32_t> read() const;
    bool write(std::uint32_t value);
    std::uint32_t getAddress() const;
    const std::string& getName() const;
    std::string_view getPermissions() const;


private:
    std::uint32_t m_address {};
    std::uint32_t m_value {};
    std::string m_name {}; 
    bool m_readable {};
    bool m_writeable {};
};