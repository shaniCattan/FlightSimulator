//
// Created by mevaseret on 12/11/2019.
//
#pragma once
#ifndef EX3_UPLUS_H

#define EX3_UPLUS_H

#include "UnaryOperator.h"

class UPlus: public UnaryOperator{

public:
     UPlus(Expression *exp1);

    double calculate() override;

    ~UPlus();
};
#endif //EX1_UPLUS_H
