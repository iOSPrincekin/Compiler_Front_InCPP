#include <iostream>
#include "lexer/Lexer.h"
#define Lexer_Debug 1
int main(int argc,char** argv) {
    std::cout << "Hello, World!" << std::endl;

#if Lexer_Debug
    Lexer l = Lexer(argv[1]);
    while (1)

    {
     Token *t = l.scan();
        cout << t->toString() << endl;
    }
#endif

    return 0;
}