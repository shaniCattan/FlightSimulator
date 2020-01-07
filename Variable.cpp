//
// Created by mevaseret on 12/11/2019.
//

#include "Variable.h"

Variable::Variable(string name1, double value1) {
    this->name = name1;
    this->value = value1;
}
// the op: ++x
Variable& Variable::operator++() {
    this->value++;
    return *this;
}
//the op: --x
Variable& Variable::operator--() {
    this->value--;
    return  *this;
}

double Variable:: calculate(){
    return this->value;
}

//the op: x++;
Variable& Variable:: operator++(int){
    this->value++;
    return *this;
}

//the op: x--
Variable&  Variable:: operator--(int){
    this->value--;
    return *this;
}

//the op+=
Variable& Variable::operator+=(double d) {
    this->value += d;
    return *this;
}

//the op: -=
Variable& Variable::operator-=(double d) {
    this->value -= d;
    return *this;
}