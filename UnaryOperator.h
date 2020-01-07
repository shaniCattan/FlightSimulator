//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_UNARYOPERATOR_H

#define EX3_UNARYOPERATOR_H

#include "Expression.h"
class UnaryOperator : public Expression{
protected:
    Expression * expression;

public:
    virtual double calculate() = 0;

    virtual ~UnaryOperator(){};


};
#endif //EX3_UNARYOPERATOR_H
