//
// Created by LEE on 4/14/20.
//

#include "While.h"

While::While() {
    expr = nullptr; stmt = nullptr;
}

void While::init(Expr *x, Stmt *s) {
    expr = x;  stmt = s;
    if( expr->type != Type::Bool ) expr->error("boolean required in while");
}

void While::gen(int b, int a) {
    after = a;                // save label a
    expr->jumping(0, a);
    int label = newlabel();   // label for stmt
    emitlabel(label); stmt->gen(label, b);
    emit("goto L" + std::to_string(b));
}