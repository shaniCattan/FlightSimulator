//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_VALUE_H

#define EX3_VALUE_H

#include "Expression.h"

class Value: public Expression{
    double Double;
public:
    Value(double d1);

    double calculate() override;

    ~Value();

};
#endif //EX3_VALUE_H
