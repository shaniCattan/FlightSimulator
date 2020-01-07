//
// Created by mevaseret on 12/11/2019.
//

#include "UPlus.h"

UPlus::UPlus(Expression *exp1) {
    this->expression = exp1;
}

double UPlus::calculate() {
    return this->expression->calculate();
}

UPlus::~UPlus() {
    delete this->expression;
}