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
    operator bool() const{
        return true;
    }
};

static const Word Word_and =  Word( "&&", Tag::AND ) ,  Word_or =  Word( "||", Tag::OR ),
        Word_eq  =  Word( "==", Tag::EQ  ),  Word_ne =  Word( "!=", Tag::NE ),
        Word_le  =  Word( "<=", Tag::LE  ),  Word_ge =  Word( ">=", Tag::GE ),
        Word_minus  =  Word( "minus", Tag::MINUS ),
        Word_True   = Word( "true",  Tag::TRUE  ),
        Word_False  =  Word( "false", Tag::FALSE ),
        Word_temp  =  Word( "t",     Tag::TEMP  );
#endif //FRONT_WORD_H
