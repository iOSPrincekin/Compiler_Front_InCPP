//
// Created by LEE on 4/12/20.
//

#include "Word.h"
Word
          *const Word::_and = new Word( "&&", Tag::AND ) ,
          *const Word::_or = new Word( "||", Tag::OR ),
          *const Word::_eq  = new Word( "==", Tag::EQ  ),
          *const Word::_ne = new Word( "!=", Tag::NE ),
          *const Word::_le  = new Word( "<=", Tag::LE  ),
          *const Word::_ge =  new Word( ">=", Tag::GE ),
          *const Word::_minus  = new Word( "minus", Tag::MINUS ),
          *const Word::_True   = new Word( "true",  Tag::TRUE  ),
          *const Word::_False  =  new Word( "false", Tag::FALSE ),
          *const Word::_temp  =  new Word( "t",     Tag::TEMP  );
Word::Word(string s, int tag):Token(tag) {
    lexeme = s;
}
string Word::toString()  {
    return lexeme;
}
