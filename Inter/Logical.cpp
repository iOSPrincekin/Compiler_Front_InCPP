//
// Created by LEE on 4/13/20.
//

#include "Logical.h"
#include "Temp.h"

Logical::Logical(Token *tok, Expr *x1, Expr *x2):Expr(tok, nullptr) {
    expr1 = x1;
    expr2 = x2;
    type = check(expr1->type,expr2->type);
    if (type == nullptr) error("type error");
}

Type* Logical::check(Type* p1, Type* p2) {
    if (p1 == Type::Bool && p2  == Type::Bool) return Type::Bool;
    else return nullptr;
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

string Logical::toString() {
    return expr1->toString()+" "+op->toString()+" "+expr2->toString()+"\n";
}