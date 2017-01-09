/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Register.cpp
 * Author: seyfullah
 *
 * Created on October 22, 2016, 8:41 PM
 */

#include "Register.h"

Register::Register(string RegisterName, int RegisterValue) {
    name = RegisterName;
    value = RegisterValue;
}

Register::Register(const Register& CopyRegister) : name(CopyRegister.name), value(CopyRegister.value){
}

Register& Register::operator=(const Register& AssigRegister) {
    name = AssigRegister.name;
    value = AssigRegister.value;
}

void Register::SetName(string RegisterName) {
    name = RegisterName;
}

void Register::SetValue(int RegisterValue) {
    value = RegisterValue;
}

string Register::GetName() const{
    return name;
}

int Register::GetValue() const{
    return value;
}