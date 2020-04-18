//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_DO_H
#define FRONT_DO_H


#include "Expr.h"
#include "Stmt.h"

class Do :public Stmt{
public:
    Expr *expr; Stmt* stmt;
    Do();
    void init(Stmt* s, Expr* x);
    virtual void gen(int b, int a);


};


#endif //FRONT_DO_H
