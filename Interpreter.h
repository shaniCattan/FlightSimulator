//
// Created by mevaseret on 14/11/2019.
//
#pragma once
#ifndef EX3_INTERPRETER_H
#define EX3_INTERPRETER_H
#include <string>
#include <map>
#include <stack>
#include "Expression.h"
#include "VarSuper.h"
extern map <string, VarSuper*> variables;
using namespace std;

extern int client_socket;
extern map <string, VarSuper*> variables;

constexpr auto DOUBLE_ARRAY_SIZE = 36;
extern double doubleArr[DOUBLE_ARRAY_SIZE];
extern bool programIsLive;
extern map<string, int> indexMap;

bool isNum(const std::string& str);
bool isAnOperand(char at);
bool isVar(const std::string& str);
bool isDigit(char i);
bool isLetter(char i);
char whichSign(const std::string& s, unsigned int& i);

class Interpreter{
    map<char, int > precedenseMap;
    stack<char> operatorStack;
    stack< Expression*> expressionStack;

    void makeAndPushNewExp();
    bool isPrecedenceOkay(char &at);
    void buildPrecedenceMap();

public:
    Expression* interpret(string mainString);
};
#endif //EX3_INTERPRETER_H