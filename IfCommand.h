//
// Created by mevaseret on 29/12/2019.
//

#pragma once
#ifndef UNTITLED2_IFCOMMAND_H
#define UNTITLED2_IFCOMMAND_H

#include "ConditionParser.h"
#include "Parser.h"

class IfCommand : public ConditionParser{
public:

    int execute(vector<string> vecOfstrings, int index);

    ~IfCommand();
};

#endif //UNTITLED2_IFCOMMAND_H
