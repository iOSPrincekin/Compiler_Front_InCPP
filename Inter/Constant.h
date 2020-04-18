//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_CONSTANT_H
#define FRONT_CONSTANT_H


#include "Expr.h"

class Constant: public Expr {
public:
    Constant(Token* tok, Type* p);
    Constant(int i);

    void jumping(int t, int f);

};

 static  Constant
        *Constant_True  = new Constant(Word::_True,Type::Bool),
         *Constant_False = new Constant(Word::_False,Type::Bool);

#endif //FRONT_CONSTANT_H
