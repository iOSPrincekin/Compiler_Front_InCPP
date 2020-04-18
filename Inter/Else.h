//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_ELSE_H
#define FRONT_ELSE_H


#include "Stmt.h"
#include "Expr.h"

class Else : public Stmt{
public:
    Expr *expr; Stmt *stmt1, *stmt2;
    Else(Expr* x, Stmt* s1, Stmt* s2);
    virtual void gen(int b, int a);
};


#endif //FRONT_ELSE_H
