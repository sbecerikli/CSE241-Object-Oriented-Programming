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
//	int adress;
};

struct Memory
{
	unsigned int adress;
	unsigned int value;
};

//Functions Prototypes
int ReadFile(string fileName);

/***************************/
void InitRegisters();
void InitMemory();
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
void InstructionJmp(Register Register1, int LineAdress);
void InstructionJmp(int LineAdress);
int InstructionHlt();
void InstructionPrn(Register Register1);
/***************************/
int ParseString(string Line);
int RunCPU(string FileName, int Mode);
bool IsNumeric(string str);
Register& FindRegisterByName(string RegisterName);
//Register& FindRegisterByAdress(int RegisterAdress);
Memory& FindMemoryAddress(int Address);
void Trace(string Line);
void Trace2(string Line, int MemoryAdress);
void PrintMemory();
int CustomAtoi(string str);
string CustomItoa(int i);
string SkipWhiteSpace(string Str);
string CustomToUpper(string Str);
/***************************/

extern Register MyRegisters[5];
extern Memory MyMemory[50];
extern string Lines[256];
extern string ParsedLine[3];

extern int DEBUG;
#endif
