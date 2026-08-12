#include "../Register.h"
#include "../RegisterBank.h"

#include <cassert>
#include <cstdint>

void testRegisterRead()
{
    Register reg{0x08, "DATA", true, true};

    auto result{reg.read()};

    assert(result.has_value());
    assert(*result == 0);
}

void testNonReadableRegister()
{
    Register reg{0x04, "STATUS", false, true};

    auto result{reg.read()};

    assert(!result.has_value());
}

void testRegisterWrite()
{
    Register reg{0x08, "DATA", true, true};

    assert(reg.write(0xDEADBEEF));

    auto result{reg.read()};

    assert(result.has_value());
    assert(*result == 0xDEADBEEF);
}

void testReadOnlyRegister()
{
    Register reg{0x04, "STATUS", true, false};

    assert(!reg.write(0x12345678));

    auto result{reg.read()};

    assert(result.has_value());
    assert(*result == 0);
}

void testBankRead()
{
    RegisterBank bank{};

    auto result{bank.read(0x00)};

    assert(result.has_value());
    assert(*result == 0);
}

void testInvalidBankRead()
{
    RegisterBank bank{};

    auto result{bank.read(0x10)};

    assert(!result.has_value());
}

void testSuccessfulBankWrite()
{
    RegisterBank bank{};

    auto writeResult{bank.write(0x08, 0xDEADBEEF)};

    assert(writeResult == WriteResult::Success);

    auto result{bank.read(0x08)};

    assert(result.has_value());
    assert(*result == 0xDEADBEEF);
}

void testReadOnlyBankWrite()
{
    RegisterBank bank{};

    auto writeResult{bank.write(0x04, 0x12345678)};

    assert(writeResult == WriteResult::ReadOnly);

    auto result{bank.read(0x04)};

    assert(result.has_value());
    assert(*result == 0);
}

void testInvalidBankWrite()
{
    RegisterBank bank{};

    auto writeResult{bank.write(0x10, 0x12345678)};

    assert(writeResult == WriteResult::InvalidAddress);
}

int main()
{
    testRegisterRead();
    testNonReadableRegister();
    testRegisterWrite();
    testReadOnlyRegister();

    testBankRead();
    testInvalidBankRead();
    testSuccessfulBankWrite();
    testReadOnlyBankWrite();
    testInvalidBankWrite();
}