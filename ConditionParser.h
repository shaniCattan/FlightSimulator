//
// Created by shani on 1/3/20.
//
#pragma once
#ifndef UNTITLED2_CONDITIONPARSER_H

#define UNTITLED2_CONDITIONPARSER_H

#include "Command.h"
using namespace std;

class ConditionParser : public Command {
public:
    virtual int execute(vector<string> vecOfstrings, int index) = 0;
protected:
    virtual double checkCondition(vector<string> vecOfstrings, int index);

    virtual vector<string> createScopeVector(vector<string> vecOfstrings, int index);

    virtual ~ConditionParser(){}

};

#endif //UNTITLED2_CONDITIONPARSER_H