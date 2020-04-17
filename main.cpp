#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"

#define Lexer_Debug 0
#define HashTable_Debug 0
#define Parser_Debug 1
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

#if HashTable_Debug
   Hashtable t = Hashtable();
    Word wKey1 = Word("first_key",Tag::AND);
    Token *val1 = new Token('j');
    t.put(wKey1,val1);

    Word wKey2 = Word("first_key",Tag::AND);
    Token *val2 = new Token('k');
    t.put(wKey2,val2);

    Word wKey3 = Word("first_key_1",Tag::AND);
    Token *val3 = new Token('l');
    t.put(wKey3,val3);

    Token* newVal1 = static_cast<Word *>(t.get(wKey1));
    Token* newVal2 = static_cast<Word *>(t.get(wKey2));
    Token* newVal3 = static_cast<Word *>(t.get(wKey3));
    cout << newVal1->toString() << endl;
    cout << newVal2->toString() << endl;
    cout << newVal3->toString() << endl;
#endif

#if Parser_Debug
    Lexer l = Lexer(argv[1]);
    Parser *parse = new Parser(&l);
    parse->program();
#endif

    return 0;
}