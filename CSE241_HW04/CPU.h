/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CPU.h
 * Author: seyfullah
 *
 * Created on October 21, 2016, 10:37 PM
 */
#include <iostream>
#include "Register.h"
#include "Memory.h"
#include <vector>
using namespace std;

#ifndef CPU_H
#define CPU_H

class CPU {

private:
    vector<Register> CPURegisters;
    vector<string> ParsedLine;
    Memory CPUMemory;
    bool IsHalted;
    int PC;
    int DEBUG;
public:
    //Constructors
    CPU();
    CPU(vector<Register> CustomRegister, Memory CPUMem);
    CPU(int i);
    void SetPC(const int ProgCounter);
    void SetRegister(const Register CPUReg, const int index);

    int GetPC();

    void PrintAll();
    void print();
    int execute(string Line, Memory mem);

    bool Halted();

    void InitRegisters();
    void InitMemory();

    vector<Register> GetRegisters();
    vector<string> GetParsedLine();

    void SetIsHalted(bool Status) {IsHalted = Status;}

    bool GetIsHalted() {return IsHalted;}

    void SetDebug(int x) {DEBUG = x;}

    void SetMemory(Memory mem) {CPUMemory = mem;}

    Memory GetMemory() {return CPUMemory;}
    int GetDebug() {return DEBUG;}

    void InstructionMov(Register& Register1, Register& Register2);
    void InstructionMov(Register& Register1, int Constant);
    void InstructionMov(Register& Register1, string adress);
    void InstructionMov(string adress, Register& Register1);
    void InstructionMov(string adress, int Constant);

    Register InstructionAdd(Register& Register1, Register& Register2);
    Register InstructionAdd(Register& Register1, int Constant);
    Register InstructionAdd(Register& Register1, string adress);
    Register InstructionSub(Register& Register1, Register& Register2);
    Register InstructionSub(Register& Register1, int Constant);
    Register InstructionSub(Register& Register1, string adress);

    void InstructionJmp(Register Register1, const int LineAdress);
    void InstructionJmp(const int LineAdress);
    void InstructionJpn(Register Register1, const int LineAdress);
    void InstructionPrn(const Register Register1);
    void InstructionPrn(const int Constant);

    int InstructionHlt();

    int ParseString(string Line);
    bool IsNumeric(string str);
    Register& FindRegister(string RegisterName);
    Memory& FindMemoryAddress(int Address);
    void Trace(string Line);
    void Trace2(string Line, int MemoryAdress);
    int CustomAtoi(string str);
    string CustomToUpper(const string Str);
};




#endif /* CPU_H */

