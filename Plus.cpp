//
// Created by mevaseret on 11/11/2019.
//

#include "Plus.h"
//the constructor:
Plus::Plus( Expression *left1, Expression *right1){
    this->left = left1;
    this->right = right1;
}

double Plus::calculate() {
    return this->left->calculate() + this->right->calculate();
}
//destructor:
Plus::~Plus(){
    delete this->left;
    delete this->right;
}

