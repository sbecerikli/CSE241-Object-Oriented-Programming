cmake_minimum_required(VERSION 3.6)
project(CSE241_HW04)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp Register.cpp Register.h CPUProgram.cpp CPUProgram.h CPU.cpp CPU.h Memory.cpp Memory.h Computer.h Computer.cpp)
add_executable(CSE241_HW04 ${SOURCE_FILES})