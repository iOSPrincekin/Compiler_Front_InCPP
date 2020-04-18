//
// Created by LEE on 4/14/20.
//

#include "Not.h"

Not::Not(Token* tok, Expr* x2):Logical(tok,x2,x2) {
    type = check(expr1->type,expr2->type);
    if (type == nullptr) error("type error");
}

void Not::jumping(int t, int f) {
    expr2->jumping(f,t);
}

string Not::toString() {
    return op->toString()+" "+expr2->toString()+"\n";
}