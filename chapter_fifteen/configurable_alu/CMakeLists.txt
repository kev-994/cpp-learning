cmake_minimum_required(VERSION 3.20)

project(ALU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ALU
    src/main.cpp
)

target_include_directories(ALU PRIVATE
    include
)

add_executable(ALU_tests
    tests/test_ALU.cpp
)

target_include_directories(ALU_tests PRIVATE
    include
)