cmake_minimum_required(VERSION 3.6)
project(CSE241_HW06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES _mainTester.cpp Register.cpp Register.h CPUProgram.cpp CPUProgram.h CPU.cpp CPU.h Memory.cpp Memory.h Computer.h Computer.cpp CPUProgramDyn.cpp CPUProgramDyn.h requiredIncs.h)
add_executable(CSE241_HW06 ${SOURCE_FILES})