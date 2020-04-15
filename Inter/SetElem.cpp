//
// Created by LEE on 4/14/20.
//

#include "SetElem.h"

SetElem::SetElem(Access *x, Expr *y) {
    array = x->array;
    index = x->index;
    expr = y;
    if (check(x->type,expr->type) == Type_NULL) error("type error");
}

Type SetElem::check(Type p1, Type p2) {
    if ( p1 == p2 ) return p2;
    else if ( Type::numeric(p1) && Type::numeric(p2) ) return p2;
    else return Type_NULL;
}

void SetElem::gen(int b, int a) {
    string s1 = index->reduce()->toString();
    string s2 = expr->reduce()->toString();
    emit(array->toString() + " [ " + s1 + " ] = " + s2);
}