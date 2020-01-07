//
// Created by mevaseret on 29/12/2019.
//
#include "IfCommand.h"

int IfCommand::execute(vector<string> vecOfstrings, int index) {
    // create a subVector which contains only the commands in the scope of the condition
    vector<string> scope = createScopeVector(vecOfstrings, index);
    // if the condition is satisfied execute the scope
    if (checkCondition(vecOfstrings, index) == 1) {
        Parser *p = new Parser();
        p->parser(scope);
    }
    // return the index of the next command after the scope of the condition end
    // plus 5 because of the two brackets and the condition itself (x > y -> 3 arguments)
    return scope.size() + 5;
}

IfCommand::~IfCommand() {
}
