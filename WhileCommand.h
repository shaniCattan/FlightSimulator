//
// Created by mevaseret on 29/12/2019.
//
#pragma once
#ifndef EX3_WHILECOMMAND_H

#define EX3_WHILECOMMAND_H

#include "ConditionParser.h"
#include "Parser.h"

class WhileCommand: public ConditionParser  {

    int execute(vector<string> vecOfstrings, int index);

    ~WhileCommand();

};

#endif //EX3_WHILECOMMAND_H
