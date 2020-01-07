//
// Created by mevaseret on 29/12/2019.
//

#include "DefineVarCommand.h"



int DefineVarCommand::execute(vector<string> vecOfstrings, int index) {

    parseString(vecOfstrings, index);
    auto returnValue = 5;
    VarSuper *v;
    if (vecOfstrings[index + 2] == "<-") {
        v = new VarIn(this->name, this->sim);
    } else if (vecOfstrings[index + 2] == "->") {
        v = new VarOut(this->name, this->sim);
    } else {// then it is the '=' case":
        v = new VarEqual(this->name, this->sim);
        returnValue = 4;
    }

    //adding the instance to the map:
    variables[this->name] = v;

    return returnValue;
}

void DefineVarCommand::parseString(vector<string> vecOfstrings, int index) {
    //cutting out the brackets and all the unwanted chars:
    //always need to cut the first 2 chars, and 2 chars at the end:
    this->name = vecOfstrings[index + 1];
    int length = vecOfstrings[index + 4].length();
    this->sign = vecOfstrings[index + 2];
    if (this->sign.compare("=") == 0) {
        this->sim = vecOfstrings[index + 3];
    } else {
        this->sim = vecOfstrings[index + 4].substr(2, length - 4);
    }
}

DefineVarCommand::~DefineVarCommand() {}




