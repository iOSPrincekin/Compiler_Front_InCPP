//
// Created by LEE on 4/14/20.
//

#include "Rel.h"
#include "../symbols/Array.h"

Rel::Rel(Token *tok, Expr *x1, Expr *x2):Logical(tok,x1,x2) {

}
Type* Rel::check(Type* p1, Type* p2) {
    if(Array * t1 = dynamic_cast<Array*>(p1))
    {
        if(Array * t2 = dynamic_cast<Array*>(p2)){
            return nullptr;
        }
    }
    if( p1 == p2 ) return (Type*)Type_Bool;
    return nullptr;
}

void Rel::jumping(int t, int f) {
    Expr* a = expr1->reduce();
    Expr* b = expr2->reduce();
    string test = a->toString() + " " + op->toString() + " " + b->toString() + "\n";
    emitjumps(test, t, f);
}
