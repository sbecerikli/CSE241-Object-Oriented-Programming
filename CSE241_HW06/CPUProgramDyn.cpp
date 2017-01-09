/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * File:   CPUProgramDyn.cpp
 * Author: seyfullah
 *
 * Created on October 30, 2016, 8:41 PM
 */

#include <cstdlib>
#include "CPUProgramDyn.h"


CPUProgramDyn::CPUProgramDyn() {
	sizeX = 0;
    capacity = 200;
    option = 0;
    Lines = new string[capacity];
}
CPUProgramDyn::CPUProgramDyn(string FileName) {
    sizeX = findLineCount(FileName);
    capacity = 200;
    option = 0;
    Lines = new string[capacity];
    ReadFile(FileName);
}

CPUProgramDyn::CPUProgramDyn(int optionX) {
    capacity = 200;
    option = 0;
    sizeX = 0;
    Lines = new string[capacity];
};

CPUProgramDyn::~CPUProgramDyn() {
    delete[] Lines;
}

CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn &other) {
    Lines = new string[200];
    for (int i = 0; i < other.size(); ++i) {
        Lines[i] = other.Lines[i];
    }
    setSize(other.size());
    setCapacity(other.getCapacity());
    SetOption(other.GetOption());

}
void CPUProgramDyn::SetAllLines(string* allLines){
    for (int i = 0; i < size(); ++i) {
        Lines[i] = allLines[i];
    }
}

string* CPUProgramDyn::ReadFile(string FileName) {
    string line;
    int i = 0;

    ifstream MyFile(FileName.c_str());
   	
    if (MyFile.is_open())
    {
        while (getline (MyFile, line))
        {
            Lines[i] = line;
            setSize(size()+1);
            ++i;
        }
        MyFile.close();
        return Lines;
    }
    else
    {
        cout << "Unable to open file";
        return new string[1];
    }
}

int CPUProgramDyn::findLineCount(string FileName){
	string line;
    int i = 0;
    ifstream MyFile(FileName.c_str());
    
    if (MyFile.is_open())
    {
        while (getline (MyFile, line))
        {
            ++i;
        }
        MyFile.close();
        return i;
    }
    else
    {
        return -1;
    }
}

string CPUProgramDyn::getLine(int Index) {
    return Lines[Index];
}

string* CPUProgramDyn::GetAllLines() const {
    return Lines;
}



string CPUProgramDyn::operator[](const int i) {
    if(i < 0 || i >= size()){
        cout << "Index out of bounds" << endl;
        return "";
    }
    return getLine(i);
}

CPUProgramDyn CPUProgramDyn::operator+(const string instruction) {
    if(size() == getCapacity()){
        string* tempLines = new string[getCapacity() + 10];
        setCapacity(getCapacity() + 10);
        for (int i = 0; i < size(); ++i) {
            tempLines[i] = Lines[i];
        }
        tempLines[size()] = instruction;
        setSize(size() + 1);
        SetAllLines(tempLines);
        return *this;
    }
    else{
        Lines[size()] = instruction;
        setSize(size()+1);
        return *this;
    }
}

CPUProgramDyn CPUProgramDyn::operator+=(const string instruction) {
    if(size() == getCapacity()){
        string* tempLines = new string[getCapacity() + 10];
        setCapacity(getCapacity() + 10);
        for (int i = 0; i < size(); ++i) {
            tempLines[i] = Lines[i];
        }
        tempLines[size()] = instruction;
        setSize(size() + 1);
        SetAllLines(tempLines);
        return *this;
    }
    else{
        Lines[size()] = instruction;
        setSize(size()+1);
        return *this;
    }
}

CPUProgramDyn CPUProgramDyn::operator+(const CPUProgramDyn& other){
    if(getCapacity() < other.size()){
        string* tempLines = new string[getCapacity() + other.getCapacity()];
        setCapacity(getCapacity() + other.getCapacity());
        for (int i = 0; i < size(); ++i) {
            tempLines[i] = Lines[i];
        }
        for (int j = size(), k = 0; j < size() + other.size(); ++j, ++k) {
            tempLines[j] = other.Lines[k];
        }
        setSize(size() + other.size());
        SetAllLines(tempLines);
        return *this;
    }
    else{
        for (int i = size(), k = 0; k < other.size(); ++k, ++i) {
            Lines[i] = other.Lines[k];
        }
        setSize(size() + other.size());
        return *this;
    }
}

ostream &operator<<(ostream &os, const CPUProgramDyn &program) {
    for (int i = 0; i < program.size(); ++i) {
        os << "Lines: " << program.Lines[i] << endl;
    }
    return os;
}

bool CPUProgramDyn::operator==(const CPUProgramDyn &other) const {
    return GetAllLines() == other.GetAllLines();
}

bool CPUProgramDyn::operator!=(const CPUProgramDyn &other) {
    return GetAllLines() != other.GetAllLines();
}

bool CPUProgramDyn::operator<(const CPUProgramDyn &other) {
    return size() < other.size();
}

bool CPUProgramDyn::operator<=(const CPUProgramDyn &other) {
    return size() <= other.size();
}

bool CPUProgramDyn::operator>(const CPUProgramDyn &other) {
    return size() > other.size();
}

bool CPUProgramDyn::operator>=(const CPUProgramDyn &other) {
    return size() >= other.size();
}
//PreDecrement
CPUProgramDyn CPUProgramDyn::operator--() {
    Lines[size() - 1] = "";
    setSize(size() - 1);
    return *this;
}
//PostDecrement
CPUProgramDyn CPUProgramDyn::operator--(int i) {
    CPUProgramDyn temp;
    temp.setSize(size());
    temp.setCapacity(getCapacity());
    temp.SetAllLines(Lines);
    temp.SetOption(GetOption());

    Lines[size() - 1] = "";
    setSize(size() - 1);
    return temp;
}

CPUProgramDyn CPUProgramDyn::operator()(int begin, int end) {
    CPUProgramDyn temp;
    string* tempLines = new string[end - begin + 1];
    for (int i = begin, k = 0; i < end; ++i, ++k) {
        tempLines[k] = Lines[i];
    }
    temp.setSize(end - begin);
    temp.SetAllLines(tempLines);
    return temp;
}
