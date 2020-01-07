//
// Created by shani on 12/30/19.
//

#include "PrintCommand.h"

void PrintCommand::parseString(std::string s) {
    // if we need to print a string
    if (s[1] == '"') {
        this->print = s.substr(2, s.length() - 4);
        // if it is an expression
    } else {
        this->print = std::to_string(stringToDouble(s.substr(1, s.length() - 2)));
    }
}

int PrintCommand::execute(std::vector<std::string> v, int index) {
    parseString(v[index + 1]);
    std::cout << this->print << endl;
    return 2;
}

PrintCommand::~PrintCommand() {}