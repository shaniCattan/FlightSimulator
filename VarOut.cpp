//
// Created by mevaseret on 02/01/2020.
//

#include "VarOut.h"
#include "Interpreter.h"
#include "ConnectCommand.h"


VarOut::VarOut(string name1, string sim1){
    this->name.swap(name1);
    this->sim.swap(sim1);
    this->value = 0;
}

void VarOut::set(string s) {
    auto* i = new Interpreter();
    Expression* e = i->interpret(s);
    this->value = e->calculate();
    delete i;
    auto command = "set " + this->sim + " " + std::to_string(this->value) + "\r\n";
    ConnectCommand::updateSimulator(command);
}

double VarOut::getValue() {
    return this->value;
}

VarOut::~VarOut() {}
