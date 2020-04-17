//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_TYPE_H
#define FRONT_TYPE_H


#include "../lexer/Word.h"
#include <iostream>

class Type: public Word {
public:
    int width = 0;          // width is used for storage allocation
    Type(string s, int tag, int w);
    static bool numeric(Type* p);
    static Type* max(Type* p1, Type* p2 );
    friend bool operator==(const Type& l, const Type& r){
     return l.lexeme == r.lexeme;
    }
    friend bool operator!=(const Type& l, const Type& r){
        return l.lexeme != r.lexeme;
    }
};
 static const Type
         *Type_Int   =  new Type( "int",   Tag::BASIC, 4 ),
         *Type_Float =  new Type( "float", Tag::BASIC, 8 ),
         *Type_Char  =  new Type( "char",  Tag::BASIC, 1 ),
         *Type_Bool  =  new Type( "bool",  Tag::BASIC, 1 ),
         *Type_NULL  =  new Type( "NULL",  Tag::BASIC, 1 );

#endif //FRONT_TYPE_H
