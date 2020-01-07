//
// Created by mevaseret on 02/01/2020.
//
#pragma once
#ifndef EX3_VARIN_H

#define EX3_VARIN_H

#include "VarSuper.h"

class VarIn : public VarSuper {
    string sim;
    double *valuePtr;
    double *initializeValuePtr();

public:

    VarIn(string name1, string sim1);

    void set(string s) override;

    double getValue() override;

    ~VarIn();

};

#endif //EX3_VARIN_H
