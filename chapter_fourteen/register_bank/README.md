# Register Bank Simulator

A lightweight **C++20 simulation of a memory-mapped hardware register bank**, designed to model basic register access, permissions, and error handling.

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-20-blue?style=for-the-badge&logo=cplusplus" alt="C++20">
  <img src="https://img.shields.io/badge/Testing-assert-success?style=for-the-badge" alt="Testing">
</p>

---

## Overview

This project simulates a small hardware register bank containing four 32-bit registers.

Each register has:

- A memory address
- A name
- A 32-bit value
- Read permissions
- Write permissions

The simulator provides a command-line interface for reading and writing registers while handling invalid addresses and access violations.

### Register Map

| Address | Register | Permissions |
|:-------:|:---------|:-----------:|
| `0x00` | `CONTROL` | `R/W` |
| `0x04` | `STATUS` | `R` |
| `0x08` | `DATA` | `R/W` |
| `0x0C` | `CONFIG` | `R/W` |

---

## Project Structure

```text
register_bank/
├── Register.h
├── Register.cpp
├── RegisterBank.h
├── RegisterBank.cpp
├── main.cpp
├── README.md
└── tests/
    └── RegisterBankTests.cpp
```

### `Register`

Models an individual hardware register.

Responsibilities:

- Store register state
- Enforce read/write permissions
- Perform register reads
- Perform register writes

A read returns:

```cpp
std::optional<std::uint32_t>
```

This allows a failed read to be represented by `std::nullopt`.

Writes return `bool` to indicate whether the operation was successful.

### `RegisterBank`

Models the collection of memory-mapped registers.

The bank locates registers using their addresses and performs read/write operations on them.

Write operations return:

```cpp
enum class WriteResult
{
    Success,
    InvalidAddress,
    ReadOnly
};
```

This provides the caller with information about **why** a write failed rather than simply returning `false`.

---

## Example

### Writing to a register

```text
> 2
Address: 0x08
Value: 0xDEADBEEF

Write was successful.
```

### Reading the register

```text
> 1
Address: 0x08

0x08: 3735928559
```

### Register display

```text
Address  Name     Value       Permissions
0x00     CONTROL  0x00000000  R/W
0x04     STATUS   0x00000000  R
0x08     DATA     0xDEADBEEF  R/W
0x0C     CONFIG   0x00000000  R/W
```

### Invalid operation

Attempting to write to the read-only `STATUS` register:

```text
> 2
Address: 0x04
Value: 0x12345678

Register is read-only.
```

---

## Design

The project separates **register behaviour** from **user-interface logic**.

The `Register` and `RegisterBank` classes do not print messages to the user. Instead, they return information about the result of an operation.

For example:

```text
Register::write()
      │
      ├── true
      └── false

RegisterBank::write()
      │
      ├── Success
      ├── ReadOnly
      └── InvalidAddress
```

`main()` is responsible for converting these results into user-facing messages.

This keeps the register model independent from the command-line interface.

---

## Testing

Automated tests are located in:

```text
tests/RegisterBankTests.cpp
```

The test suite uses the standard C++ `assert` facility to verify:

- Readable register reads
- Non-readable register reads
- Successful writes
- Rejected writes to read-only registers
- Valid register addresses
- Invalid register addresses
- Correct `WriteResult` values
- Register values changing after successful writes

Tests are compiled separately from the application so that the test executable has its own `main()`.

---

## Building

### Requirements

- C++20-compatible compiler
- GCC or Clang

### Build the application

From the project root:

```bash
g++ -std=c++20 \
    chapter_fourteen/register_bank/Register.cpp \
    chapter_fourteen/register_bank/RegisterBank.cpp \
    chapter_fourteen/register_bank/main.cpp \
    -o build/register_bank
```

Run:

```bash
./build/register_bank
```

### Build the tests

```bash
g++ -std=c++20 \
    chapter_fourteen/register_bank/Register.cpp \
    chapter_fourteen/register_bank/RegisterBank.cpp \
    chapter_fourteen/register_bank/tests/RegisterBankTests.cpp \
    -o build/testregbank
```

Run:

```bash
./build/testregbank
```

If all assertions pass, the test executable exits successfully without producing output.

---

## C++ Concepts Practiced

- Classes and objects
- Encapsulation
- Public and private members
- Constructors
- Member initializer lists
- Member functions
- `const` member functions
- References
- `std::string`
- `std::string_view`
- `std::optional`
- `enum class`
- `auto`
- Returning objects by value
- Separate interface and implementation
- Automated testing with `assert`

---

## Future Improvements

- Replace individually declared registers with a collection
- Support a configurable register map
- Improve command-line input validation
- Add more realistic hardware register behaviour
- Model special-purpose registers
- Add status and interrupt registers
- Introduce CMake for project configuration and testing

---

## Motivation

This project was built as a small exercise in **C++ systems programming**, using a hardware-inspired problem to practise class design, encapsulation, error handling, and automated testing.