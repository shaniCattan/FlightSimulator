//
// Created by shani on 1/3/20.
//

#include "ConditionParser.h"

#include <algorithm>

double ConditionParser::checkCondition(vector<string> vecOfstrings, int index){
    string condition = vecOfstrings[index + 1] + vecOfstrings[index + 2] + vecOfstrings[index + 3];
    Interpreter *i = new Interpreter();
    Expression *e = i->interpret(condition);
    return e->calculate();
}

vector<string> ConditionParser::createScopeVector(vector<string> vecOfstrings, int index) {
    const auto whileBegin = vecOfstrings.begin() + index + 5;
    auto it = std::find(vecOfstrings.begin() + index, vecOfstrings.end(), std::string{"}"});
    std::vector<std::string> subVector = {whileBegin, it};
    return subVector;
}