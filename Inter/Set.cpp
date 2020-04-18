//
// Created by LEE on 4/15/20.
//

#include "Set.h"

Set::Set(Id *i, Expr *x) {
    id = i; expr = x;
    if ( check(id->type, expr->type) == Type_NULL ) error("type error");
}

Type* Set::check(Type* p1, Type* p2) {
    if ( Type::numeric(p1) && Type::numeric(p2) ) return p2;
    else if ( p1 == Type_Bool && p2 == Type_Bool ) return p2;
    else return nullptr;
}

void Set::gen(int b, int a) {
    emit( id->toString() + " = " + expr->gen()->toString());
}