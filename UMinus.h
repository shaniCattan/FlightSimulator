//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_UMINUS_H

#define EX3_UMINUS_H

#include "UnaryOperator.h"
class UMinus: public UnaryOperator{
public:

    UMinus( Expression *exp1);

    double calculate() override ;

    ~UMinus();
};
#endif //EX3_UMINUS_H
