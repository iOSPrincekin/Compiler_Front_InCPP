//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_REL_H
#define FRONT_REL_H


#include "Logical.h"

class Rel: public Logical {
public:
    Rel(Token* tok, Expr* x1, Expr* x2);
    virtual Type* check(Type* p1, Type* p2);
    void jumping(int t, int f);
};


#endif //FRONT_REL_H
