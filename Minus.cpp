//
// Created by mevaseret on 12/11/2019.
//

#include "Minus.h"
//constructor:
Minus::Minus(Expression *left1, Expression *right1) {
    this->left = left1;
    this->right = right1;
}

double Minus::calculate() {
    return this->left->calculate() - this->right->calculate();
}

//destructor:
Minus::~Minus() {
    delete this->left;
    delete this->right;
}

