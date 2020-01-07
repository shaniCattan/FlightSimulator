//
// Created by mevaseret on 03/01/2020.
//

#include "Boolean.h"

#include <stdexcept>

Boolean::Boolean(Expression *left1, Expression *right1, string sign1) {
    this->left = left1;
    this->right = right1;
    this->sign = sign1;
}

double Boolean::calculate() {
    auto leftValue = left->calculate();
    auto rightValue = right->calculate();

    auto returnValue = double{};
    if (this->sign == "==") {
        returnValue = leftValue == rightValue;
    } else if (this->sign == "!=") {
        returnValue = leftValue != rightValue;
    } else if (this->sign == "<=") {
        returnValue = leftValue <= rightValue;
    } else if (this->sign == ">=") {
        returnValue = leftValue >= rightValue;
    } else if (this->sign == ">") {
        returnValue = leftValue > rightValue;
    } else if (this->sign == "<") {
        returnValue = leftValue < rightValue;
    }   else {
        throw std::runtime_error(std::string("Invalid boolean operator") + this->sign);
    }

    return static_cast<double>(returnValue);
}

Boolean::~Boolean() {
    delete this->left;
    delete this->right;
}



