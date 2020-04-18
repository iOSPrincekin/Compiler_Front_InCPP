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
    static Constant
            *const True,
            *const False;
    void jumping(int t, int f);

};



#endif //FRONT_CONSTANT_H
