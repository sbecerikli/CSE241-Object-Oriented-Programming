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
#include <vector>
using namespace std;

#ifndef CPU_H
#define CPU_H

class CPU {

private:
    vector<Register> CPURegisters;
    vector<string> ParsedLine;
    bool IsHalted;
    int PC;
    int DEBUG;
public:
    //Constructors
    CPU();
    CPU(vector<Register> CustomRegister);

    void SetPC(const int ProgCounter);
    void SetRegister(const Register CPUReg, const int index);

    int GetPC();

    void PrintAll();

    int Execute(const string Line);

    bool Halted();

    void InitRegisters();

    vector<Register> GetRegisters();
    vector<string> GetParsedLine();

    void SetIsHalted(bool Status) {IsHalted = Status;}

    bool GetIsHalted() {return IsHalted;}

    void SetDebug(int x) {DEBUG = x;}

    int GetDebug() {return DEBUG;}

    void InstructionMov(Register& Register1, Register& Register2);
    void InstructionMov(Register& Register1, int Constant);

    Register InstructionAdd(Register& Register1, Register& Register2);
    Register InstructionAdd(Register& Register1, int Constant);
    Register InstructionSub(Register& Register1, Register& Register2);
    Register InstructionSub(Register& Register1, int Constant);

    void InstructionJmp(Register Register1, const int LineAdress);
    void InstructionJmp(const int LineAdress);
    void InstructionPrn(const Register Register1);
    void InstructionPrn(const int Constant);
    
    int ParseString(string Line);
    bool IsNumeric(string str);
    Register& FindRegister(string RegisterName);
    void Trace(string Line);
    int CustomAtoi(string str);
    string CustomToUpper(const string Str);
};




#endif /* CPU_H */

