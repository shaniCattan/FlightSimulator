//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_VARIABLE_H
#define EX3_VARIABLE_H

#include <string>
#include "Expression.h"

class Variable:  public Expression{

    string name;
    double value;

public:
    Variable(string name1, double value1);

    Variable& operator++();

    Variable& operator--();

    double calculate () override;

    Variable& operator++(int);

    Variable& operator--(int);

    Variable& operator+=(double d);

    Variable& operator-=(double d);


};
#endif //EX3_VARIABLE_H
