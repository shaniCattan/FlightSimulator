//
// Created by mevaseret on 02/01/2020.
//

#pragma once
#ifndef EX3_VAROUT_H

#define EX3_VAROUT_H
#include "VarSuper.h"
class VarOut: public VarSuper{
    string sim;
    double value;
public:

    VarOut(string name1, string sim1);

    void set(string s) override ;

    double getValue() override ;

    ~VarOut();

};

#endif //EX3_VAROUT_H
