//
// Created by mevaseret on 29/12/2019.
//
#pragma once
#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H

#include "Command.h"
#include <cstring>

extern int client_socket;

class ConnectCommand: public Command{

    std::uint16_t port;
    std::string ip;

public:
    int execute(vector<string> vecOfstrings, int index) override ;
    static void updateSimulator(const std::string& s);
    void parseString(string s);

    ~ConnectCommand();
};

#endif //EX3_CONNECTCOMMAND_H
