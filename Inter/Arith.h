//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_ARITH_H
#define FRONT_ARITH_H


#include "Op.h"

class Arith: public Op {
public:
    Expr* expr1, *expr2;
    Arith(Token* tok, Expr* x1, Expr *x2);
    virtual Expr* gen();
    virtual string toString();

};


#endif //FRONT_ARITH_H
