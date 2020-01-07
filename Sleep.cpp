//
// Created by mevaseret on 02/01/2020.
//


#include "Sleep.h"

int Sleep::execute(vector<string> vecOfstrings, int index) {
    parseString(vecOfstrings[index+1]);
    std::this_thread::sleep_for(std::chrono::milliseconds(this->sleep));
    return 2;
}

void Sleep::parseString(string s) {
    this->sleep = static_cast<int>(stringToDouble(s.substr(1,s.length()-2)));
}


Sleep::~Sleep() {}