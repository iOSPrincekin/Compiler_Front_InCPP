//
// Created by LEE on 4/12/20.
//

#include "Type.h"
  Type
          *const Type::Int   =  new Type( "int",   Tag::BASIC, 4 ),
          *const Type::Float =  new Type( "float", Tag::BASIC, 8 ),
          *const Type::Char  =  new Type( "char",  Tag::BASIC, 1 ),
          *const Type::Bool  =  new Type( "bool",  Tag::BASIC, 1 );
Type::Type(string s, int tag, int w):Word(s,tag) {

    width = w;
}

bool Type::numeric(Type* p) {
    if (p == Type::Char || p == Type::Int || p == Type::Float) return true;
    else return false;
}

Type* Type::max(Type* p1, Type* p2) {
    if ( ! numeric(p1) || ! numeric(p2) ) return nullptr;
    else if ( p1 == Type::Float || p2 == Type::Float ) return (Type*)Type::Float;
    else if ( p1 == Type::Int  || p2 == Type::Int   ) return (Type*)Type::Float;
    else return (Type*)Type::Char;
}