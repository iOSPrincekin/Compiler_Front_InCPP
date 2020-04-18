//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_WORD_H
#define FRONT_WORD_H

#include <string>

#include "Token.h"
#include "Tag.h"
using namespace std;
class Word : public Token{
public:
    string lexeme;
    Word(string s, int tag);
    virtual string toString ();
    static  Word
            *const _and,
            *const _or ,
            *const _eq,
            *const _ne,
            *const _le,
            *const _ge,
            *const _minus,
            *const _True,
            *const _False,
            *const _temp;
    friend bool operator<(const Word& l, const Word& r){
        return l.lexeme < r.lexeme;
    }
};
#endif //FRONT_WORD_H
