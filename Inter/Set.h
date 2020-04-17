//
// Created by LEE on 4/15/20.
//

#ifndef FRONT_SET_H
#define FRONT_SET_H


#include "Stmt.h"
#include "Expr.h"
#include "Id.h"

class Set : public Stmt{
public:
    Id *id;  Expr *expr;
    Set(Id *i, Expr *x);
    Type* check(Type* p1, Type* p2);
    void gen(int b, int a);

};


#endif //FRONT_SET_H
