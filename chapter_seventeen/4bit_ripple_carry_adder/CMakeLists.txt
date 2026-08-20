cmake_minimum_required(VERSION 3.20)

project(ALU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ALU
    src/main.cpp
    src/LogicGates.cpp
    src/TruthTable.cpp
    src/Adder.cpp
)

target_include_directories(ALU PRIVATE
    include
)

add_executable(testAdder
    tests/testAdder.cpp
    src/LogicGates.cpp
    src/TruthTable.cpp
    src/Adder.cpp
)

target_include_directories(testAdder PRIVATE
    include
)


