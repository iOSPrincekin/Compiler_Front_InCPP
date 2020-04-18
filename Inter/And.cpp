//
// Created by LEE on 4/14/20.
//

#include "And.h"

And::And(Token *tok, Expr *x1, Expr *x2):Logical(tok,x1,x2) {
    type = check(expr1->type,expr2->type);
    if (type == nullptr) error("type error");
}

void And::jumping(int t, int f) {
    int label = f != 0 ? f : newlabel();
    expr1->jumping(0, label);
    expr2->jumping(t,f);
    if( f == 0 ) emitlabel(label);
}