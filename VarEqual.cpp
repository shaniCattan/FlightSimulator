//
// Created by mevaseret on 02/01/2020.
//

#include <memory>

#include "VarEqual.h"
#include "Interpreter.h"

VarEqual::VarEqual(string name1, const std::string& valStr)
{
    this->name = std::move(name1);
    set(valStr);

}

void VarEqual::set(std::string s) {
    auto i = std::unique_ptr<Interpreter>(new Interpreter{});
    Expression *e = i->interpret(s);
    this->value = e->calculate();
}

double VarEqual::getValue() {
    return this->value;
}

VarEqual::~VarEqual() {}
