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
    friend bool operator<(const Word& l, const Word& r){
        return l.lexeme < r.lexeme;
    }
};

static const Word *Word_and = new Word( "&&", Tag::AND ) ,  *Word_or = new Word( "||", Tag::OR ),
        *Word_eq  = new Word( "==", Tag::EQ  ),  *Word_ne = new Word( "!=", Tag::NE ),
        *Word_le  = new Word( "<=", Tag::LE  ), * Word_ge =  new Word( ">=", Tag::GE ),
        *Word_minus  = new Word( "minus", Tag::MINUS ),
        *Word_True   = new Word( "true",  Tag::TRUE  ),
        *Word_False  =  new Word( "false", Tag::FALSE ),
        *Word_temp  =  new Word( "t",     Tag::TEMP  );
#endif //FRONT_WORD_H
