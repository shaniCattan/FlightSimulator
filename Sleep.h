//
// Created by mevaseret on 02/01/2020.
//
#pragma once
#ifndef EX3_SLEEP_H

#define EX3_SLEEP_H

#include "Command.h"

class Sleep: public Command{

    int sleep;

public:

    int execute(vector<string> vecOfstrings, int index);
    void parseString(string s);

    ~Sleep();
};

#endif //EX3_SLEEP_H
