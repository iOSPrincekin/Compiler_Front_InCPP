//
// Created by LEE on 4/13/20.
//

#include "If.h"

If::If(Expr* x, Stmt* s) {
    expr = x;  stmt = s;
    if( expr->type != Type_Bool ) expr->error("boolean required in if");
}

void If::gen(int b, int a) {
    int label = newlabel(); // label for the code for stmt
    expr->jumping(0, a);     // fall through on true, goto a on false
    emitlabel(label); stmt->gen(label, a);
}