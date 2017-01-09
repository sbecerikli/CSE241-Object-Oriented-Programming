/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CPUProgramDyn.h
 * Author: seyfullah
 *
 * Created on October 30, 2016, 8:41 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <getopt.h>

using namespace std;

#ifndef CPUProgramDyn_H
#define CPUProgramDyn_H

class CPUProgramDyn {
private:
    string* Lines;
    int sizeX;
    int capacity;
    int option;
public:
    CPUProgramDyn();
    ~CPUProgramDyn();   
    CPUProgramDyn(const CPUProgramDyn& other);

    CPUProgramDyn(string FileName);
    CPUProgramDyn(int option);
    string* ReadFile(string FileName);
    string* GetAllLines() const;
    void SetAllLines(string* allLines);
    string getLine(int Index);
    void setSize(int s) {sizeX = s;}
    int size() const {return sizeX;}
    void SetOption(int x) {option = x;}
    int GetOption() const{return option;}
    

    void setCapacity(const int c ) { capacity = c;}
    int getCapacity() const {return capacity;}

    int findLineCount(string FileName);
    //Operator overloadings
    CPUProgramDyn& operator=(const CPUProgramDyn& other);


    string operator[](const int i);
    CPUProgramDyn operator+(const string instruction);
    CPUProgramDyn operator+=(const string instruction);
    CPUProgramDyn operator+(const CPUProgramDyn& otherCPUProgramDyn);
    friend ostream &operator<<(ostream &os, const CPUProgramDyn &program);
    bool operator==(const CPUProgramDyn& other) const;
    bool operator!=(const CPUProgramDyn& other);
    bool operator<(const CPUProgramDyn& other);
    bool operator<=(const CPUProgramDyn& other);
    bool operator>(const CPUProgramDyn& other);
    bool operator>=(const CPUProgramDyn& other);
    CPUProgramDyn operator--();
    CPUProgramDyn operator--(int i);

    CPUProgramDyn operator()(int begin, int end);
};



#endif /* CPUProgramDyn_H */

