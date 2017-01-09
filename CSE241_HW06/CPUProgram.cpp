/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * File:   CPUProgram.cpp
 * Author: seyfullah
 *
 * Created on October 22, 2016, 8:41 PM
 */

#include <cstdlib>
#include "CPUProgram.h"
CPUProgram::CPUProgram() {
    Lines.push_back("");
    option = 1;
}
CPUProgram::CPUProgram(string FileName) {
    ReadFile(FileName);
}

CPUProgram::CPUProgram(int optionX) {
    option = optionX;
    Lines.push_back("");
};

void CPUProgram::SetAllLines(vector<string> allLines){
    Lines = allLines;
}

vector<string> CPUProgram::ReadFile(string FileName) {
    string line;
    int i = 0;
    ifstream MyFile(FileName.c_str());
    Lines.push_back("");
    if (MyFile.is_open())
    {
        while (getline (MyFile, line))
        {
            Lines.push_back(line);
            ++i;
        }
        MyFile.close();
        return Lines;
    }
    else
    {
        cout << "Unable to open file";
        return vector<string>();
    }
}

string CPUProgram::getLine(int Index) {
    return Lines.at(Index);
}

vector<string> CPUProgram::GetAllLines() const {
    return Lines;
}

int CPUProgram::size() const{
    return Lines.size();
}

string CPUProgram::operator[](const int i) {
    if(i < 0 || i >= Lines.size()){
        cout << "Index out of bounds" << endl;
        return "";
    }
    return getLine(i);
}

CPUProgram CPUProgram::operator+(const string instruction) {
    CPUProgram newCpuProgram;
    newCpuProgram.SetAllLines(Lines);
    newCpuProgram.Lines.push_back(instruction);
    return newCpuProgram;
}

CPUProgram* CPUProgram::operator+=(const string instruction) {
    Lines.push_back(instruction);
    return this;
}

CPUProgram* CPUProgram::operator+(const CPUProgram& other){
    Lines.insert(Lines.end(), other.Lines.begin(), other.Lines.end());
    return this;
}

ostream &operator<<(ostream &os, const CPUProgram &program) {
    for (int i = 0; i < program.Lines.size(); ++i) {
        os << "Lines: " << program.Lines.at(i) << endl;
    }
    return os;
}

bool CPUProgram::operator==(const CPUProgram &other) const {
    return GetAllLines() == other.GetAllLines();
}

bool CPUProgram::operator!=(const CPUProgram &other) {
    return GetAllLines() != other.GetAllLines();
}

bool CPUProgram::operator<(const CPUProgram &other) {
    return size() < other.size();
}

bool CPUProgram::operator<=(const CPUProgram &other) {
    return size() <= other.size();
}

bool CPUProgram::operator>(const CPUProgram &other) {
    return size() > other.size();
}

bool CPUProgram::operator>=(const CPUProgram &other) {
    return size() >= other.size();
}
//PreDecrement
void CPUProgram::operator--() {
    Lines.erase(Lines.begin()+size());
}
//PostDecrement
void CPUProgram::operator--(int i) {
    Lines.erase(Lines.begin()+size());
}

CPUProgram CPUProgram::operator()(int begin, int end) {
    CPUProgram newCPUProgram;
    vector<string> newInstructions(Lines.begin() + begin, Lines.begin() + end + 1);
    newCPUProgram.SetAllLines(newInstructions);
    return newCPUProgram;
}
