//
// Created by mevaseret on 29/12/2019.
//
#pragma once
#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include <vector>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include "unordered_map"
#include <thread>
#include "Interpreter.h"


class Command{
public:
    virtual int execute(std::vector<std::string> vecOfstrings, int index) = 0;
    double stringToDouble(const std::string& s);

    virtual ~Command(){};
};
#endif //EX3_COMMAND_H
