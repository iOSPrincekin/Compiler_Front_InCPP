//
// Created by LEE on 4/13/20.
//

#include "Logical.h"
#include "Temp.h"

Logical::Logical(Token *tok, Expr *x1, Expr *x2):Expr(tok, Type_NULL) {
    expr1 = x1;
    expr2 = x2;
    type = check(expr1->type,expr2->type);
    if (type == Type_NULL) error("type error");
}

Type Logical::check(Type p1, Type p2) {
    if (p1 == Type_Bool && p2  == Type_Bool) return Type_Bool;
    else return Type_NULL;
}

Expr* Logical::gen() {
    int f = newlabel(); int a = newlabel();
    Temp *temp = new Temp(type);
    this->jumping(0,f);
    emit(temp->toString() + " = true");
    emit("goto L" + std::to_string(a));
    emitlabel(f); emit(temp->toString() + " = false");
    emitlabel(a);
    return temp;
}