//
// Created by mevaseret on 02/01/2020.
//
#pragma once
#ifndef EX3_VARSUPER_H

#define EX3_VARSUPER_H
#include <string>
using namespace std;

class VarSuper {

protected:
    string name;

public:

    virtual void set(string s) = 0;

    virtual double getValue() = 0;

    virtual ~VarSuper(){}
};

#endif //EX3_VARSUPER_H
