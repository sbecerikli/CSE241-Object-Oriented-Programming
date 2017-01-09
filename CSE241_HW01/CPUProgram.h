/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CPUProgram.h
 * Author: seyfullah
 *
 * Created on October 22, 2016, 8:41 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H

class CPUProgram {
private:
    vector<string> Lines;
public:
    CPUProgram(string FileName);
    vector<string> ReadFile(string FileName);
    vector<string> GetAllLines();
    string GetLine(int Index);
    int NumberOfLines();
};



#endif /* CPUPROGRAM_H */

