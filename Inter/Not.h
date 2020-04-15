//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_NOT_H
#define FRONT_NOT_H


#include "Logical.h"

class Not: public Logical {
public:
    Not(Token* tok, Expr* x2);
    void jumping(int t, int f);
    string toString();
};


#endif //FRONT_NOT_H
