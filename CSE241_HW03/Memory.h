//
// Created by seyfullah on 26.10.2016.
//

#ifndef CSE241_HW04_MEMORY_H
#define CSE241_HW04_MEMORY_H

#include  <vector>
#include <iostream>

using namespace std;

class Memory {
private:
    unsigned int adress;
    unsigned int value;
    int option;
    vector<Memory> myMemory;
public:
    Memory();
    Memory(int i);
    Memory(unsigned int Adress, unsigned int Value);
    void SetAdress(unsigned int Adress);
    void SetValue(unsigned int Value);
    void SetMem(unsigned int Adress, unsigned int Value);
    vector<Memory> GetMyMemory() {return myMemory;}
    Memory& getMem(int i);
    unsigned int GetAdress() const;
    unsigned int GetValue() const;
    void PrintAll();
    friend ostream &operator<<(ostream &output, const Memory &mem);
};


#endif //CSE241_HW04_MEMORY_H
