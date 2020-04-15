//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_SETELEM_H
#define FRONT_SETELEM_H


#include "Stmt.h"
#include "Id.h"
#include "Access.h"

class SetElem: public Stmt {
public:
    Id *array;  Expr* index;  Expr* expr;
    SetElem(Access* x, Expr* y);
    Type check(Type p1, Type p2);
    void gen(int b, int a);
};


#endif //FRONT_SETELEM_H
