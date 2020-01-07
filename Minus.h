//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_MINUS_H
#define EX3_MINUS_H

#include "BinaryOperator.h"

class Minus: public BinaryOperator{

public:

    Minus(Expression *left1, Expression *right1);

    double calculate() override;

    ~Minus();
};
#endif //EX3_MINUS_H
