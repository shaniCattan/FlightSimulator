//
// Created by mevaseret on 11/11/2019.
//
#pragma once
#ifndef EX1_BINARYOPERATOR_H
#define EX1_BINARYOPERATOR_H

#include "Expression.h"
/**
 * Expression Interface
 */
class BinaryOperator : public Expression{
protected:
    Expression* left;
    Expression* right;

public:
    virtual double calculate() override = 0;

    virtual ~BinaryOperator(){}
};

#endif //EX1_BINARYOPERATOR_H
