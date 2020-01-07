//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_MUL_H
#define EX3_MUL_H

#include "BinaryOperator.h"

class Mul : public BinaryOperator {

public:
    Mul(Expression *left1, Expression *right1);

    double calculate() override;

    ~Mul();

};

#endif //EX3_MUL_H
