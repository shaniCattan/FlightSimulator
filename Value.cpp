//
// Created by mevaseret on 12/11/2019.
//

#include "Value.h"

Value::Value(double d1) {
    this->Double = d1;
}

double Value::calculate() {
    return this->Double;
}

Value::~Value() {
}

