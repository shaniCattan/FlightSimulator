//
// Created by mevaseret on 29/12/2019.
//
#pragma once
#ifndef EX3_PRINTCOMMAND_H

#define EX3_PRINTCOMMAND_H

#include "Command.h"

class PrintCommand: public Command{
    string print;
public:
    int execute(vector<string> vecOfstrings, int index);
    void parseString(string s);

    ~PrintCommand();
};
#endif //EX3_PRINTCOMMAND_H
