//
// Created by LEE on 4/12/20.
//

#include "Token.h"

Token::Token(int t) {
    tag = t;
}
string Token::toString()  {
    std::string s;
    s += char(tag);
    return s;
}