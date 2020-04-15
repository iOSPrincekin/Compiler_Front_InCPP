//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_IF_H
#define FRONT_IF_H


#include "Expr.h"
#include "Stmt.h"

class If : public Stmt {
public:
    Expr *expr; Stmt *stmt;
    If(Expr* x, Stmt* s);
    void gen(int b, int a);

};


#endif //FRONT_IF_H
