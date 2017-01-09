//
// Created by sbecerikli on 11/3/16.
//

#ifndef CSE241_HW04_COMPUTER_H
#define CSE241_HW04_COMPUTER_H

#include "CPU.h"
#include "CPUProgram.h"
#include "Memory.h"


class Computer{

private:
    CPU ComputerCpu;
    CPUProgram ComputerCpuProgram;
    Memory ComputerMemory;
    int option;
public:
    Computer(CPU &CPUx, CPUProgram &CPUProgramx, Memory &Memoryx, int optionX);
    Computer(int opt);

    void setCPU(CPU cpux);
    void setCPUProgram(CPUProgram cpuprogramx);
    void setMemory(Memory memoryx);

    CPU& getCPU();
    CPUProgram& getCPUProgram();
    Memory& getMemory();

    void execute(string filename, int opt);

};


#endif //CSE241_HW04_COMPUTER_H
