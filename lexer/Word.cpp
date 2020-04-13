//
// Created by LEE on 4/12/20.
//

#include "Word.h"

Word::Word(string s, int tag):Token(tag) {
    lexeme = s;
}
string Word::toString()  {
    return lexeme;
}