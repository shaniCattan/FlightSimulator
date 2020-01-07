//
// Created by mevaseret on 29/12/2019.
//
#pragma once
#ifndef EX3_PARSER_H
#include <iostream>
#include<string>
#include <vector>
#include <unordered_map>
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "Sleep.h"
#include "VarSuper.h"
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "Interpreter.h"

#define EX3_PARSER_H


class Parser {
    //the map of commands
    unordered_map<string, Command *> mapCommand;
public:
    void parser(vector<string> vec);

private:
    void buildMapCommand();

};

#endif //EX3_PARSER_H