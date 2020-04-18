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
    static  Type
            *const Int ,
            *const Float ,
            *const Char ,
            *const Bool ;
    static bool numeric(Type* p);
    static Type* max(Type* p1, Type* p2 );
    friend bool operator==(const Type& l, const Type& r){
     return l.lexeme == r.lexeme;
    }
    friend bool operator!=(const Type& l, const Type& r){
        return l.lexeme != r.lexeme;
    }
};


#endif //FRONT_TYPE_H
