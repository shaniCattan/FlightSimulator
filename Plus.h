//
// Created by mevaseret on 11/11/2019.
//
#pragma once
#ifndef EX3_PLUS_H

#define EX3_PLUS_H

#include "BinaryOperator.h"

class Plus: public BinaryOperator{

public:
    Plus(Expression *left1, Expression *right1);

    double calculate() override ;

    ~Plus();
};
#endif //EX3_PLUS_H
