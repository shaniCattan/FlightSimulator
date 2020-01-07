//
// Created by mevaseret on 12/11/2019.
//

#include "Mul.h"

Mul::Mul(Expression *left1, Expression *right1) {
    this->left = left1;
    this->right = right1;
}

double Mul::calculate() {
    return this->left->calculate() * this->right->calculate();
}

Mul::~Mul() {
    delete this->left;
    delete(this->right);
}

