//
// Created by seyfullah on 26.10.2016.
//

#include "Memory.h"

Memory::Memory() {
    option = 0;
    adress = 0;
    value = 0;
    myMemory.reserve(50);
    for (int j = 0; j < 50; ++j) {
        myMemory.push_back(Memory(j, 0));
    }
}

Memory::Memory(unsigned int Adress, unsigned int Value) {
    option = 0;
    adress = Adress;
    value = Value;
    myMemory.reserve(50);

}

Memory::Memory(int i) {
    option = i;
    myMemory.reserve(50);
    for (int j = 0; j < 50; ++j) {
        myMemory.push_back(Memory(j, 0));
    }
}
void Memory::SetAdress(unsigned int Adress) {
    adress = Adress;
}

void Memory::SetValue(unsigned int Value) {
    value = Value;
}

unsigned int Memory::GetAdress() const{
    return adress;
}

unsigned int Memory::GetValue() const {
    return value;
}

void Memory::SetMem(unsigned int Adress, unsigned int Value) {
    myMemory.at(Adress).SetValue(Value);
}
Memory& Memory::getMem(int i)  {
    return myMemory.at(i);
}

void Memory::PrintAll() {
    cout << "Memory Values: " << endl;
    for (int i = 0; i < myMemory.capacity(); ++i) {
        cout << "[" << i << "] -> " << myMemory.at(i).GetValue() << endl;
    }
}

ostream& operator<<(ostream &output, const Memory &mem) {
    cout << "Memory Adress " << mem.GetAdress() << ": " << mem.GetValue() << endl;
}