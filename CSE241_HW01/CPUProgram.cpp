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

#include "CPUProgram.h"

CPUProgram::CPUProgram(string FileName) {
    ReadFile(FileName);
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

string CPUProgram::GetLine(int Index) {
    return Lines.at(Index);
}

vector<string> CPUProgram::GetAllLines() {
    return Lines;
}

int CPUProgram::NumberOfLines() {
    return Lines.size();
}
