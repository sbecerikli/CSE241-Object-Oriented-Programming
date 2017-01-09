/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: seyfullah
 *
 * Created on October 21, 2016, 10:36 PM
 */

#include <cstdlib>
#include "CPU.h"
#include "CPUProgram.h"
#include "Computer.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv){
    if(argc < 3){
        cout << "Usage: " << argv[0] << " filename" << " option" << endl;
        return -1;

    }
    const char* filename = argv[1];
    int option = atoi(argv[2]);

    //Testing class Memory
    Memory myMemory(option);
    //index, value
    myMemory.SetMem(0, 100);
    cout << myMemory.getMem(0) << endl;
    myMemory.PrintAll();

    //Testing class CPU
    CPU myCPU(0);
    myCPU.execute("MOV #0, R1", myMemory);
    myCPU.execute("MOV R1, #1", myMemory);
    myCPU.print();
    myMemory.PrintAll();

    //Testing class CPUProgram
    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(filename);
    cout << myCPUProgram.getLine(1) << endl;
    cout << myCPUProgram.getLine(myCPUProgram.size() - 1) << endl;

    myCPU.SetPC(1);
    //Testing class Computer
    Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
    Computer myComputer2(option);

    myComputer2.setCPU( myComputer1.getCPU() );
    myComputer2.setCPUProgram(myComputer1.getCPUProgram() );
    myComputer2.setMemory(myComputer1.getMemory() );

    myComputer2.execute(filename, option);


}