//
// Created by shani on 1/4/20.
//

#include "Command.h"


double Command::stringToDouble(const std::string& s) {
    auto* i = new Interpreter();
    Expression* e = i->interpret(s);
    delete i;
    return e->calculate();
}

