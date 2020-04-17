//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_LEXER_H
#define FRONT_LEXER_H

#include "Hashtable.h"
#include "Word.h"
#include <ios>
#include <fstream>

class Lexer {
public:
    int line;
    Lexer();
    Lexer(string file_path);
    char peek = ' ';
    Token* scan();

private:
    fstream file_in;
    Hashtable words;
    void reserve(Word w);
    void setup();
    void readch();
    bool readch(char c);




};


#endif //FRONT_LEXER_H
