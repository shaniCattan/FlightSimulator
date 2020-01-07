//
// Created by mevaseret on 02/01/2020.
//

#include "VarIn.h"
#include "Interpreter.h"
#include "OpenServerCommand.h"

VarIn::VarIn(string name1, string sim1) {
    this->name.swap(name1);
    this->sim.swap(sim1);
    this->valuePtr = initializeValuePtr();
}

void VarIn::set(string s) {
    Interpreter *i = new Interpreter();
    Expression *e = i->interpret(s);
    *this->valuePtr = e->calculate();
}

double *VarIn::initializeValuePtr() {
    return &doubleArr[indexMap[this->sim]];
}

double VarIn::getValue() {
    return *this->valuePtr;
}

VarIn::~VarIn() {}

