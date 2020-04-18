//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_UNARY_H
#define FRONT_UNARY_H


#include "Expr.h"
#include "Op.h"

class Unary: public Op {
public:
    Expr* expr;
    Unary(Token* tok, Expr* x);

    virtual Expr* gen();
    string toString();
};


#endif //FRONT_UNARY_H
