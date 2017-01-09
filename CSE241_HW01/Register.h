/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Register.h
 * Author: seyfullah
 *
 * Created on October 21, 2016, 10:38 PM
 */
#include <string>
using namespace std;

#ifndef REGISTER_H
#define REGISTER_H

class Register {
private:
    string name;
    int value;    
public:
    Register(string name, int value);
    Register(const Register& CopyRegister);
    Register& operator=(const Register& AssigRegister);
    void SetName(string RegisterName);
    void SetValue(int RegisterValue);
    string GetName() const;
    int GetValue() const;
};

#endif /* REGISTER_H */

