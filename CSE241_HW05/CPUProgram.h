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
#include <getopt.h>

using namespace std;

#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H

class CPUProgram {
private:
    vector<string> Lines;
    int option;
public:
    CPUProgram();
    CPUProgram(string FileName);
    CPUProgram(int option);
    vector<string> ReadFile(string FileName);
    vector<string> GetAllLines() const;
    void SetAllLines(vector<string> allLines);
    string getLine(int Index);
    int size() const;
    void SetOption(int x) {option = x;}
    int GetOption() {return option;}


    //Operator overloadings

    string operator[](const int i);
    CPUProgram operator+(const string instruction);
    CPUProgram* operator+=(const string instruction);
    CPUProgram* operator+(const CPUProgram& otherCPUProgram);
    friend ostream &operator<<(ostream &os, const CPUProgram &program);
    bool operator==(const CPUProgram& other) const;
    bool operator!=(const CPUProgram& other);
    bool operator<(const CPUProgram& other);
    bool operator<=(const CPUProgram& other);
    bool operator>(const CPUProgram& other);
    bool operator>=(const CPUProgram& other);
    void operator--();
    void operator--(int i);

    CPUProgram operator()(int begin, int end);
};



#endif /* CPUPROGRAM_H */

