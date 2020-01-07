//
// Created by mevaseret on 29/12/2019.
//
#pragma once
#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H
#include "Command.h"
#include "VarIn.h"
#include "VarEqual.h"
#include "VarOut.h"


class DefineVarCommand: public Command{
private:
    string name;
    string sim;
    string sign;

public:
    int execute(vector<string> vecOfstrings, int index) override ;
    void parseString(vector<string> vecOfstrings, int index);

    ~DefineVarCommand();

};

#endif //EX3_DEFINEVARCOMMAND_H
