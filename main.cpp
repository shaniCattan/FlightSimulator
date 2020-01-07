#include "Parser.h"
#include "Lexer.h"

int main(int argc, char* argv[]) {
    (void)argc;
    Lexer *l1;
    l1 = new Lexer(argv[1]);
    auto p1 =  new Parser();
    p1->parser(l1->lexer());
    programIsLive = false;
    close(client_socket);
    return 0;
}