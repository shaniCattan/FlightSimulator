//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_DIV_H
#define EX3_DIV_H

#include "BinaryOperator.h"

class Div: public BinaryOperator{

public:
    Div(Expression *left1, Expression *right1 );

    double calculate() override;

    ~Div();
};
#endif //EX3_DIV_H
