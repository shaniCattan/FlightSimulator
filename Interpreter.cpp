//
// Created by mevaseret on 14/11/2019.
//

#include <stdexcept>
#include <regex>


#include "Interpreter.h"
#include "Variable.h"
#include "Value.h"
#include "UMinus.h"
#include "UPlus.h"
#include "Minus.h"
#include "Plus.h"
#include "Div.h"
#include "Boolean.h"
#include "Mul.h"

map<string, VarSuper *> variables;

std::string strip(const std::string& input)
{
    auto begin = input.begin();
    for (; begin != input.end(); ++begin) {
        if (!std::isspace(*begin)) {
            break;
        }
    }
    if (begin == input.end()) {
        return "";
    }

    auto end = input.rbegin();
    for (; end != input.rend(); ++end) {
        if (!std::isspace(*end)) {
            break;
        }
    }

    return std::string(begin, end.base());
}

bool isValidVariableCharacter(char c) {
    return (c == '_') || isLetter(c) || isDigit(c);
}

bool isNum(const std::string &str) {
    try {
        std::stod(str);
        return true;
    }
    catch (std::exception &) {
        return false;
    }
}

bool isDigit(char i) {
    return static_cast<bool>(std::isdigit(static_cast<int>(i)));
}

bool isLetter(char i) {
    return static_cast<bool>(std::isalpha(static_cast<int>(i)));
}

bool isVar(const std::string &str) {
    //if the first char is a letter
    if (str[0] == '_' || isLetter(str[0])) {
        return std::all_of(str.begin(), str.end(), isValidVariableCharacter);
    }
    return false;
}

bool isAnOperand(char at) {
    return at == '(' || at == ')' || at == '+' || at == '-' || at == '*' || at == '/' || at == '$' || at == '@'
           || at == '=' || at == '!' || at == '<' || at == '>' || at == '#' || at == '%';
}

//checking which sig or condition it is and returnig our sign for it:
char whichSign(const std::string &s, unsigned int &i) {
    static std::map<std::string, char> operatorsConversion = {
            {">=", '%'},
            {"<=", '#'},
            {"==", '='},
            {"!=", '!'}
    };
    //first check if it is a uMinus or a uPlus:
    if (i == 0 || s[i - 1] == '(') {
        if (s[i] == '-') {
            return '$';
        }
        if (s[i] == '+') {
            return '@';
        }
    }

    //checking if it is one of the boolean conditions:
    auto stringOperator = s.substr(i, 2);
    if (operatorsConversion.count(stringOperator)) {
        i++;
        return operatorsConversion.at(stringOperator);
    }
    // if it none returning the current char from the string:
    return s[i];
}


Expression *Interpreter::interpret(string mainString) {

    //building the precednce map:
    buildPrecedenceMap();
    //going over the string by reading a single char each time
    for (unsigned int i = 0; i < mainString.length(); i++) {
        char currChar = mainString.at(i);
        //first checking if it one of the signs/conditions for which we hold  special char,
        // and updating currchar to the sign
        currChar = whichSign(mainString, i);
        //secondly, check if it is an operand. regarding all the operands.
        if (isAnOperand(currChar)) {
            //we need to take out of expressionStack till we meet the (.
            if (currChar == ')') {
                //checking for no extra unvalid bracket ')'
                if (!this->operatorStack.empty()) {
                    while (operatorStack.top() != '(') {
                        makeAndPushNewExp();
                        if (this->operatorStack.empty()) {
                            throw std::runtime_error(" unvalid input, extra ')'");
                        }
                    }
                    //take out the open '(':
                    this->operatorStack.pop();
                } else {
                    throw std::runtime_error(" unvalid input, extra ')'");
                }
            } else if (isPrecedenceOkay(currChar)) {
                operatorStack.push(currChar);
            } else {
                while (!isPrecedenceOkay(currChar)) {
                    makeAndPushNewExp();
                }
                //now that precedense is okay insert operator to stack:
                operatorStack.push(currChar);
            }
        } else {//cheking if it is a var or val
            //finding the last index of the variable/num in mainString
            auto end = mainString.find_first_of("()+-*/$@=!><#%", i);
            if (std::string::npos == end) {
                end = mainString.length();
            }
            auto temp = strip(mainString.substr(i, end - i));
            i = end - 1;

            if (isVar(temp)) {
                //look for key
                if (variables.count(temp) == 0) {
                    throw std::runtime_error("variable not found");
                } else {
                    // found, make an expression variable
                    auto *var = new Variable(temp, variables.at(temp)->getValue());
                    expressionStack.push(var);
                }

            } else if (isNum(temp)) {
                //make an expression value
                auto *val = new Value(std::stod(temp));
                //insert to stack;
                expressionStack.push(val);
            } else {//it is neither, so throw exception:
                throw std::runtime_error("not valid input");
            }
        }
    }
    while (!this->operatorStack.empty()) {
        makeAndPushNewExp();
    }
    return this->expressionStack.top();
}

void Interpreter::makeAndPushNewExp() {
    char topChar = operatorStack.top();
    if (topChar == '(') {
        throw std::runtime_error("extra open bracket '(");
    } else {
        operatorStack.pop();
        //if it is a unary operator so we need to take out 1 expression
        if (topChar == '$') {
            Expression *e1 = expressionStack.top();
            expressionStack.pop();
            this->expressionStack.push(new UMinus(e1));
            //if it is an unary operator so we need to take out 1 expression
        } else if (topChar == '@') {
            Expression *e1 = expressionStack.top();
            expressionStack.pop();
            this->expressionStack.push(new UPlus(e1));
        } else {
            Expression *e2 = expressionStack.top();
            expressionStack.pop();
            Expression *e1 = expressionStack.top();
            expressionStack.pop();

            switch (topChar) {
                case '-':
                    this->expressionStack.push(new Minus(e1, e2));
                    break;
                case '+':
                    this->expressionStack.push(new Plus(e1, e2));
                    break;
                case '/':
                    this->expressionStack.push(new Div(e1, e2));
                    break;
                case '*':
                    this->expressionStack.push(new Mul(e1, e2));
                    break;
                case '=':
                    this->expressionStack.push(new Boolean(e1, e2, "=="));
                    break;
                case '!':
                    this->expressionStack.push(new Boolean(e1, e2, "!="));
                    break;
                case '<':
                    this->expressionStack.push(new Boolean(e1, e2, "<"));
                    break;
                case '>':
                    this->expressionStack.push(new Boolean(e1, e2, ">"));
                    break;
                case '#':
                    this->expressionStack.push(new Boolean(e1, e2, "<="));
                    break;
                case '%':
                    this->expressionStack.push(new Boolean(e1, e2, ">="));
                    break;
                default:
                    throw std::invalid_argument(std::string("Operator not supported: ") + topChar);
            }
        }
    }
}

bool Interpreter::isPrecedenceOkay(char &at) {
    //if operator is '(', always precedence is okay.
    //if stack is empty also okay
    if (this->operatorStack.empty()) {
        return true;
    } else {
        return (this->precedenseMap.at(at) > this->precedenseMap.at(this->operatorStack.top())) ||
               (at == '(');
    }
}

void Interpreter::buildPrecedenceMap() {

    precedenseMap.insert({'(', 0});
    precedenseMap.insert({'+', 1});
    precedenseMap.insert({'-', 1});
    //the sign of UMinus
    precedenseMap.insert({'$', 1});
    //the sign of UPlus
    precedenseMap.insert({'@', 1});
    precedenseMap.insert({'*', 2});
    precedenseMap.insert({'/', 2});
    //added this for the ex3:
    precedenseMap.insert({'=', -1});
    precedenseMap.insert({'!', -1});
    precedenseMap.insert({'<', -1});
    precedenseMap.insert({'>', -1});
    precedenseMap.insert({'#', -1});
    precedenseMap.insert({'%', -1});
}
