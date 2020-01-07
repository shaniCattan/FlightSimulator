//
// Created by mevaseret on 29/12/2019.
//

#include "Parser.h"

void Parser::parser(vector<string> vec) {

    buildMapCommand();
    unsigned int index = 0;

    //going over the vec of strings to execute the commands
    while (index < vec.size()) {
        //if not in map then it is a var being assigned
        if (mapCommand.count(vec[index]) == 0) {
            variables[vec[index]]->set(vec[index + 2]);
            index += 3;
        } else {
            Command *c = this->mapCommand[vec[index]];
            if (c != nullptr) {
                auto returnValue = c->execute(vec, index);
                index += returnValue;
            }
        }
    }

}

void Parser::buildMapCommand() {
    this->mapCommand["openDataServer"] = new OpenServerCommand();
    this->mapCommand["connectControlClient"] = new ConnectCommand();
    this->mapCommand["var"] = new DefineVarCommand();
    this->mapCommand["while"] = new WhileCommand();
    this->mapCommand["if"] = new IfCommand();
    this->mapCommand["Sleep"] = new Sleep();
    this->mapCommand["Print"] = new PrintCommand();
}