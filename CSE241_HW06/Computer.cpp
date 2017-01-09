//
// Created by sbecerikli on 11/3/16.
//

#include "CPU.h"
#include "CPUProgram.h"
#include "Computer.h"


Computer::Computer(CPU &CPUx, CPUProgram &CPUProgramx, Memory &Memoryx, int optionX) {
    ComputerCpu = CPUx;
    ComputerCpuProgram = CPUProgramx;
    ComputerMemory = Memoryx;
    option = optionX;
}

Computer::Computer(int opt) {
    option = opt;
}

void Computer::setCPU(CPU cpux) {
    ComputerCpu = cpux;
}

void Computer::setCPUProgram(CPUProgram cpuprogramx) {
    ComputerCpuProgram = cpuprogramx;
}

void Computer::setMemory(Memory memoryx) {
    ComputerMemory = memoryx;
}

CPU& Computer::getCPU() {
    return ComputerCpu;
}

CPUProgram& Computer::getCPUProgram() {
    return ComputerCpuProgram;
}

Memory& Computer::getMemory() {
    return ComputerMemory;
}

void Computer::execute(string filename, int opt) {

    getCPUProgram().ReadFile(filename);
    getCPUProgram().SetOption(opt);
    getCPU().SetMemory(getMemory());
    getCPU().SetDebug(opt);
    cout << getCPU().GetPC() << endl;
    while(!getCPU().Halted()){
        getCPU().execute(getCPUProgram().getLine(getCPU().GetPC()), getMemory());
    }
    getCPU().PrintAll();
}
