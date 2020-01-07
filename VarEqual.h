//
// Created by mevaseret on 02/01/2020.
//
#pragma once
#ifndef EX3_VAREQUAL_H

#define EX3_VAREQUAL_H

#include "VarSuper.h"
class VarEqual: public VarSuper{
    double value;

public:

    VarEqual(std::string name, const std::string& valStr);

    void set(std::string s) override;

    double getValue() override ;

    ~VarEqual();
};



#endif //EX3_VAREQUAL_H
