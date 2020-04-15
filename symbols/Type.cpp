//
// Created by LEE on 4/12/20.
//

#include "Type.h"

Type::Type(string s, int tag, int w):Word(s,tag) {

    width = w;
}

bool Type::numeric(Type p) {
    if (p == Type_Char || p == Type_Int || p == Type_Float) return true;
    else return false;
}

const Type Type::max(Type p1, Type p2) {
    if ( ! numeric(p1) || ! numeric(p2) ) return Type_NULL;
    else if ( p1 == Type_Float || p2 == Type_Float ) return Type_Float;
    else if ( p1 == Type_Int  || p2 == Type_Int   ) return Type_Float;
    else return Type_Char;
}