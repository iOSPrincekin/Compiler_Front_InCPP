//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_AND_H
#define FRONT_AND_H


#include "Logical.h"

class And : public Logical{
public:
    And(Token* tok, Expr* x1, Expr* x2);
    void jumping(int t, int f);
};


#endif //FRONT_AND_H
