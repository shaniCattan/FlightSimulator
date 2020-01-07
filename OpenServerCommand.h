//
// Created by mevaseret on 29/12/2019.
//
#pragma once

#include <array>
#include <atomic>
#include <thread>

#include "Command.h"

extern double doubleArr[DOUBLE_ARRAY_SIZE];
extern bool programIsLive;

extern std::map<std::string, int> indexMap;

void readData(int serverSocketFd);

class OpenServerCommand : public Command {
    std::uint16_t port;

public:
    int execute(std::vector<std::string> vecOfstrings, int index) override;

    void parseString(std::string s);

    void buildMap();

    ~OpenServerCommand();

};
