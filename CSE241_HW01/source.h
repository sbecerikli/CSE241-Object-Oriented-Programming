#ifndef SOURCE_H__
#define SOURCE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Register
{
	string name;
	int value;
};

//Functions Prototypes
int ReadFile(string fileName);

/***************************/
void InitRegisters();
void InstructionMov(Register& Register1, Register& Register2);
void InstructionMov(Register& Register1, int Constant);
Register InstructionAdd(Register& Register1, Register& Register2);
Register InstructionAdd(Register& Register1, int Constant);
Register InstructionSub(Register& Register1, Register& Register2);
Register InstructionSub(Register& Register1, int Constant);
void InstructionJmp(Register Register1, int LineAdress);
void InstructionJmp(int LineAdress);
int InstructionHlt();
void InstructionPrn(Register Register1);
/***************************/
int ParseString(string Line);
int RunCPU(string FileName, int Mode);
bool IsNumeric(string str);
Register& FindRegister(string RegisterName);
void Trace(string Line);
int CustomAtoi(string str);
string SkipWhiteSpace(string Str);
string CustomToUpper(string Str);
/***************************/

extern Register MyRegisters[5];

extern string Lines[256];
extern string ParsedLine[3];

extern int DEBUG;
#endif
