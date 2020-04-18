//
// Created by LEE on 4/14/20.
//

#include "Else.h"

Else::Else(Expr* x, Stmt* s1, Stmt* s2) {
    expr = x; stmt1 = s1; stmt2 = s2;
    if( expr->type != Type_Bool ) expr->error("boolean required in if");
}

void Else::gen(int b, int a) {
    int label1 = newlabel();   // label1 for stmt1
    int label2 = newlabel();   // label2 for stmt2
    expr->jumping(0,label2);    // fall through to stmt1 on true
    emitlabel(label1); stmt1->gen(label1, a); emit("goto L" + std::to_string(a) + "\n");
    emitlabel(label2); stmt2->gen(label2, a);
}