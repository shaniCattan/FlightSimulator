//
// Created by mevaseret on 03/01/2020.
//
#pragma once
#ifndef EX3_BOOLEAN_H
#define EX3_BOOLEAN_H

#include <string>
#include "BinaryOperator.h"


class Boolean: public BinaryOperator{

    string sign;

public:
    Boolean(Expression *left1, Expression *right1, string sign1);

    double calculate() override;

    ~Boolean();
};

#endif //EX3_BOOLEAN_H