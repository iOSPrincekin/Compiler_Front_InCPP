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
};
 static const Type
         Type_Int   =  Type( "int",   Tag::BASIC, 4 ),
         Type_Float =  Type( "float", Tag::BASIC, 8 ),
         Type_Char  =  Type( "char",  Tag::BASIC, 1 ),
         Type_Bool  =  Type( "bool",  Tag::BASIC, 1 );

#endif //FRONT_TYPE_H
