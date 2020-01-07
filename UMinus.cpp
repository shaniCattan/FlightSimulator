//
// Created by mevaseret on 12/11/2019.
//

#include "UMinus.h"

UMinus::UMinus(Expression *exp1) {
    this->expression = exp1;
}

double UMinus::calculate() {
    return this->expression->calculate() *(-1);
}

UMinus::~UMinus() {
    delete this->expression;
}