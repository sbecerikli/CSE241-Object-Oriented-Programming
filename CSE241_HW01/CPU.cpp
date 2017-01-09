/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CPU.h
 * Author: seyfullah
 *
 * Created on October 22, 2016, 8:41 PM
 */

#include "CPU.h"
#include <sstream>
using namespace std;

CPU::CPU() {
    IsHalted = false;
    PC = 1;
    InitRegisters();
}

CPU::CPU(vector<Register> CustomRegister) {
    PC = 1;
    CPURegisters = CustomRegister;
}

void CPU::SetPC(const int ProgCounter) {
    PC = ProgCounter;
}

void CPU::SetRegister(const Register CPUReg, const int index) {
    CPURegisters.at(index) = CPUReg;
}

int CPU::GetPC() {
    return PC;
}

vector<Register> CPU::GetRegisters() {
    return CPURegisters;
}

vector<string> CPU::GetParsedLine() {
    return ParsedLine;
}

bool CPU::Halted() {
    if(GetIsHalted())
    {
        return true;
    }
    return false;
}

void CPU::PrintAll() {
    for (int i = 0; i < GetRegisters().size(); i++) {
        cout << GetRegisters().at(i).GetName() << " = " << GetRegisters().at(i).GetValue() << endl;
    }
    cout << "Program Counter = " << GetPC() << endl;
}

int CPU::Execute(const string Line) {

    int x = ParseString(Line);
    int posnoktalicirgul = Line.find(";");
    string TempString = Line.substr(0, posnoktalicirgul);
    //If Parsed line has more than 3 value. Instructions argument
    if (x >= 3) {
        if (CustomToUpper(ParsedLine.at(0)).compare("MOV") == 0) {
            if (!(IsNumeric(ParsedLine.at(2)))) {
                InstructionMov(FindRegister(CustomToUpper(ParsedLine.at(1))), FindRegister(CustomToUpper(ParsedLine.at(2))));
                if (GetDebug()) {
                    Trace(TempString);
                    cout << endl;
                }
            } else {
                InstructionMov(FindRegister(CustomToUpper(ParsedLine.at(1))), CustomAtoi(ParsedLine.at(2)));
                if (GetDebug()) {
                    Trace(TempString);
                    cout << endl;
                }
            }
        } else if (CustomToUpper(ParsedLine[0]).compare("ADD") == 0) {
            if (!(IsNumeric(ParsedLine[2]))) {
                InstructionAdd(FindRegister(CustomToUpper(ParsedLine.at(1))), FindRegister(CustomToUpper(ParsedLine.at(2))));
                if (GetDebug()) {
                    Trace(TempString);
                    cout << endl;
                }
            } else {
                InstructionAdd(FindRegister(CustomToUpper(ParsedLine.at(1))), CustomAtoi(ParsedLine.at(2)));
                if (GetDebug()) {
                    Trace(TempString);
                    cout << endl;
                }
            }
        } else if (CustomToUpper(ParsedLine.at(0)).compare("SUB") == 0) {
            if (!(IsNumeric(ParsedLine.at(2)))) {
                InstructionSub(FindRegister(CustomToUpper(ParsedLine.at(1))), FindRegister(CustomToUpper(ParsedLine.at(2))));
                if (GetDebug()) {
                    Trace(TempString);
                    cout << endl;
                }
            } else {
                InstructionSub(FindRegister(CustomToUpper(ParsedLine.at(1))), CustomAtoi(ParsedLine.at(2)));
                if (GetDebug()) {
                    Trace(Line);
                    cout << endl;
                }
            }
        } else if (CustomToUpper(ParsedLine.at(0)).compare("JMP") == 0) {

            if ((IsNumeric(ParsedLine.at(2)))) {
                InstructionJmp(FindRegister(CustomToUpper(ParsedLine.at(1))), CustomAtoi(ParsedLine.at(2)));
                if (GetDebug()) {
                    Trace(TempString);
                    cout << endl;
                }
            }
        } else {
            cout << "There are some syntax errors. No such instruction that: \"" << ParsedLine.at(0) << "\" on line " << GetPC() << endl;
            return -1;
        }
    } else if (x == 2) {
        if (CustomToUpper(ParsedLine.at(0)).compare("JMP") == 0) {
            InstructionJmp(CustomAtoi(ParsedLine.at(1)));
            if (GetDebug()) {
                Trace(TempString += "\t");
                cout << endl;
            }
        } else if (CustomToUpper(ParsedLine.at(0)).compare("PRN") == 0) {
            if(IsNumeric(ParsedLine.at(1)))
            {
                InstructionPrn(CustomAtoi(ParsedLine.at(1)));
            }
            else {
                InstructionPrn(FindRegister(ParsedLine.at(1)));
            }
        } else {
            cout << "There are some syntax errors. No such instruction that: \"" << ParsedLine.at(0) << "\" on line " << GetPC() << endl;
            return -1;
        }
    } else {
        if (CustomToUpper(ParsedLine.at(0)).compare("HLT") == 0) {
            if (GetDebug()) {
                Trace(TempString += "\t");
            }
            SetIsHalted(true);
        } else {
            cout << "There are some syntax errors. No such instruction that: \"" << ParsedLine[0] << "\" on line " << GetPC() << endl;
            return -1;
        }

    }
}
//Initialize All registers
void CPU::InitRegisters() {
    CPURegisters.push_back(Register("R1", 0));
    CPURegisters.push_back(Register("R2", 0));
    CPURegisters.push_back(Register("R3", 0));
    CPURegisters.push_back(Register("R4", 0));
    CPURegisters.push_back(Register("R5", 0));
}

void CPU::InstructionMov(Register& Register1, Register& Register2) {
    Register2.SetValue(Register1.GetValue());
    SetPC(GetPC() + 1);
}

void CPU::InstructionMov(Register& Register1, int Constant) {
    Register1.SetValue(Constant);
    SetPC(GetPC() + 1);
}

Register CPU::InstructionAdd(Register& Register1, Register& Register2) {
    Register1.SetValue(Register1.GetValue() + Register2.GetValue());
    SetPC(GetPC() + 1);
    return Register1;
}

Register CPU::InstructionAdd(Register& Register1, const int Constant) {
    Register1.SetValue(Register1.GetValue() + Constant);
    SetPC(GetPC() + 1);
    return Register1;
}

Register CPU::InstructionSub(Register& Register1, Register& Register2) {
    Register1.SetValue(Register1.GetValue() - Register2.GetValue());
    SetPC(GetPC() + 1);
    return Register1;
}

Register CPU::InstructionSub(Register& Register1, const int Constant) {
    Register1.SetValue(Register1.GetValue() - Constant);
    SetPC(GetPC() + 1);
    return Register1;
}

void CPU::InstructionJmp(Register Register1, const int LineAdress) {
    if (FindRegister(CustomToUpper(ParsedLine[1])).GetValue() == 0) {
        SetPC(LineAdress);
    }
    else{
        SetPC(GetPC() + 1);
    }
}

void CPU::InstructionJmp(const int LineAdress) {
    SetPC(LineAdress);
}

void CPU::InstructionPrn(const Register Register1) {
    cout << Register1.GetName() << " = " << Register1.GetValue() << endl;
    SetPC(GetPC() + 1);
}

void CPU::InstructionPrn(const int Constant) {
    cout << Constant << endl;
    SetPC(GetPC() + 1);
}
//Parses string
int CPU::ParseString(string Line) {

    ParsedLine.clear();
    string delimiter1 = ",";
    string strX = "";
    string a[3];
    //Finds semicolon index
    int posnoktalicirgul = Line.find(";");
    string sX = Line.substr(0, posnoktalicirgul);
    size_t pos = 0;
    string token;
    //Finds "," position then takes it to a new empty string with whitspace until end of string
    while ((pos = sX.find(delimiter1)) != std::string::npos) {
        token = sX.substr(0, pos);
        strX += token + " ";
        sX.erase(0, pos + delimiter1.length());
    }

    strX += sX;
    //To skip whitespace.
    istringstream WhiteSpace(strX.c_str());
    int i = 0;
    do {
        string SubStr;
        WhiteSpace >> SubStr;
        if (SubStr != "") {
            ParsedLine.push_back(SubStr);
            ++i;
        }
    } while (WhiteSpace);

    return i;
}
//Makes string to Integer
int CPU::CustomAtoi(string str) {
    int num = 0;
    int neg = 0;
    char* sX = (char*) str.c_str();
    while (isspace(*sX)) {
        sX++;
    }
    if (*sX == '-') {
        neg = 1;
        sX++;
    }
    while (isdigit(*sX)) {
        num = 10 * num + (*sX - '0'); //to find digit ascii value
        sX++;
    }
    if (neg) {
        num = -num;
    }
    return num;
}
//Makes all character UPPer
string CPU::CustomToUpper(const string Str) {
    string TempString = "";
    for (size_t i = 0; i < Str.length(); ++i) {
        TempString += toupper(Str[i]);
    }
    return TempString;
}
//Finds register by name and returns it
Register& CPU::FindRegister(string RegisterName) {
    for (int i = 0; i < CPURegisters.size() ; ++i) {
        if(CPURegisters.at(i).GetName().compare(RegisterName) == 0)
            return CPURegisters.at(i);
    }
}
//Checks the string is numeric
bool CPU::IsNumeric(string str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (isdigit(str.c_str()[i])) {
            return true;
        } else if (str.c_str()[i] == '-') {
            if (isdigit(str.c_str()[i + 1])) {
                return true;
            }

        } else {
            return false;
        }
    }
}
//Debugging
void CPU::Trace(string Line) {
    cout << Line << "\t - \t";
    for (int i = 0; i < CPURegisters.size() ; ++i) {
        cout << CPURegisters.at(i).GetName() << " = " << CPURegisters.at(i).GetValue() << " ";
    }
}
