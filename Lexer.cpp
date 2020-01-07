
#include <fstream>
#include "Lexer.h"

using namespace std;

Lexer::Lexer(char *fn) {
    this->fileName = fn;
}

vector<string> Lexer::lexer() {
    ifstream src(this->fileName);
    //the vector that will contain the splitted string
    std::vector<std::string> vecStrings;
    string strTemp;
    //if it is a space in a string in side brackets, we dont want to parse every word singularly
    //so if flag is 1 then it will not parse.
    int flagStrOfPrint = 0;
    int j;
    if (!src) {
        cout << "error opening file" << endl;
        exit(1);
    }
    std::string line;
    while (getline(src, line)) {
        // use line
        //j is the index of the beginnig of the new string.
        j = 0;
        for (unsigned int i = 0; i < line.length(); ++i) {
            //initialize strTemp:
            strTemp = "";
            //if we see a TAB: we want to skip to the next char:
            if (line[i] == '\t') {
                i++;
                j = i;
            }

            // if we see '=':before and after the equal must be a space!!!
            // we want to put everything till the end of the line in one string:
            if (line[i] == '=' && line[i - 1] == ' ' && line[i + 1] == ' ') {
                //pushing the '=' to the vec
                strTemp = "=";
                vecStrings.push_back(strTemp);
                //then pushing what is after th = till the end of the line to a string in the vec
                strTemp = line.substr(j + 2);
                vecStrings.push_back(strTemp);
                i = line.length();
            } else if (line[i] == '(') {
                flagStrOfPrint = 1;
                strTemp = line.substr(j, i - j);
                vecStrings.push_back(strTemp);
                //updating j: we want the brackets in the string!!
                j = i;
            } else if (line[i] == ')') {
                flagStrOfPrint = 0;
                strTemp = line.substr(j, i + 1 - j);
                vecStrings.push_back(strTemp);
                //updating j: we want the brackets in the string!!
                j = i + 1;
            } else if (line[i] == ' ' && !flagStrOfPrint) {
                strTemp = line.substr(j, i - j);
                vecStrings.push_back(strTemp);
                //updating j: we want the brackets in the string!!
                j = i + 1;
            } else if (line[i] == '{') {
                strTemp += line[i];
                vecStrings.push_back(strTemp);
            } else if (line[i] == '}') {
                strTemp += line[i];
                vecStrings.push_back(strTemp);
            }
        }
    }

    return vecStrings;
}