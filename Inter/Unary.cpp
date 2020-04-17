//
// Created by LEE on 4/14/20.
//

#include "Unary.h"

Unary::Unary(Token* tok, Expr* x):Op(tok, nullptr) {
    expr = x;
    type = Type::max((Type*)Type_Int,expr->type);
    if (type == Type_NULL ) error("type error");
}

Expr* Unary::gen() {
    return new Unary(op, expr->reduce());
}

string Unary::toString() {
    return op->toString()+" "+expr->toString();
}