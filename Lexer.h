//
// Created by mevaseret on 27/12/2019.
//
#pragma once
#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Lexer {
    char *fileName;
public:
    Lexer(char *fileName);

    vector<string> lexer();

};

#endif //EX3_LEXER_H
