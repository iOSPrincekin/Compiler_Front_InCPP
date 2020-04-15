//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_WHILE_H
#define FRONT_WHILE_H


#include "Stmt.h"
#include "Expr.h"

class While: public Stmt{
public:
    Expr* expr; Stmt* stmt;
    While();
    void init(Expr* x, Stmt* s);
    void gen(int b, int a);

};


#endif //FRONT_WHILE_H
