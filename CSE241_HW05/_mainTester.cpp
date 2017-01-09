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

#include "requiredIncs.h"

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

   
    //Testing class CPUProgram
    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(filename);
    //Testing class CPUProgram
    //op []
    cout << myCPUProgram[0] << endl;
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;

    //op +
    myCPUProgram = myCPUProgram + "MOV R1, #45";
    cout << myCPUProgram[myCPUProgram.size()-1] << endl;

    //op +=
    myCPUProgram += "MOV R2, #50";
    cout << myCPUProgram[myCPUProgram.size()-1] << endl;

    //op + <<
    CPUProgram myOtherCPUProgram(0);
    myOtherCPUProgram.ReadFile(filename);
    //cout << *(myCPUProgram + myOtherCPUProgram) << endl;


    cout << (myCPUProgram == myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram <= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram > myOtherCPUProgram ? "FAIL" : "DONE") << endl;

    --myOtherCPUProgram;

    cout << endl;
    cout << (myCPUProgram == myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram >= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram < myOtherCPUProgram ? "FAIL" : "DONE") << endl;


    //op ()
    cout << myCPUProgram(5, 10) << endl;


    //error check
    cout << myCPUProgram[myCPUProgram.size()] << endl;

    myCPUProgram += "";
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;


}