//
// Created by LEE on 4/14/20.
//

#include "Arith.h"
Arith::Arith(Token* tok, Expr *x1, Expr *x2):Op(tok, nullptr) {
    expr1 = x1;
    expr2 = x2;
    type = Type::max(expr1->type,expr2->type);
    if (type == Type_NULL) error("type error");
}

Expr* Arith::gen() {
    return new Arith(op, expr1->reduce(), expr2->reduce());
}

string Arith::toString()  {
    return expr1->toString()+" "+op->toString()+" "+expr2->toString();
}