//
// Created by mevaseret on 12/11/2019.
//

#include "Div.h"

Div::Div(Expression *left1, Expression *right1) {
    this->left = left1;
    this->right = right1;
}

double Div::calculate() {
    if(this->right->calculate() == 0){
        throw "can not divide by '0'!!";
    }
    return this->left->calculate() / this->right->calculate();
}

Div::~Div() {
    delete this->left;
    delete this->right;
}