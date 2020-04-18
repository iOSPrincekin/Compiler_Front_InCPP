//
// Created by LEE on 4/14/20.
//

#include "Or.h"
Or::Or(Token *tok, Expr* x1, Expr* x2): Logical(tok,x1,x2){
    type = check(expr1->type,expr2->type);
    if (type == nullptr) error("type error");
}

void Or::jumping(int t, int f) {
    int label = t != 0 ? t : newlabel();
    expr1->jumping(label, 0);
    expr2->jumping(t,f);
    if( t == 0 ) emitlabel(label);
}