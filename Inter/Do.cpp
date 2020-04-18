//
// Created by LEE on 4/14/20.
//

#include "Do.h"

Do::Do() {
    expr = nullptr;
    stmt = nullptr;
}

void Do::init(Stmt* s, Expr* x)
{
    expr = x; stmt = s;
    if( expr->type != Type::Bool ) expr->error("boolean required in do");
}

void Do::gen(int b, int a) {
    after = a;
    int label = newlabel();   // label for expr
    stmt->gen(b,label);
    emitlabel(label);
    expr->jumping(b,0);
}