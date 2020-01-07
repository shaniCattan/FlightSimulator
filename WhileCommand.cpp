//
// Created by mevaseret on 29/12/2019.
//


#include "WhileCommand.h"


int WhileCommand::execute(vector<string> vecOfstrings, int index) {
    std::vector<std::string> scope = createScopeVector(vecOfstrings, index);
    // if the condition is satisfied execute the scope
    while (checkCondition(vecOfstrings, index) == 1) {
        auto *p = new Parser();
        p->parser(scope);
        delete p;
    }
    // return the index of the next command after the scope of the condition end
    // plus 5 because of the two brackets and the condition itself (x > y -> 3 arguments)
    return static_cast<int>(scope.size() + 6);
}

WhileCommand::~WhileCommand() {

}