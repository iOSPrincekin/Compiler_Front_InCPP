//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_LOGICAL_H
#define FRONT_LOGICAL_H


#include "Expr.h"

class Logical: public Expr {
public:
    Expr *expr1, *expr2;

    Logical(Token* tok,Expr* x1,Expr* x2);

    Type* check(Type* p1,Type* p2);

    Expr* gen();

    string toString();
};


#endif //FRONT_LOGICAL_H
