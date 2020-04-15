//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_OR_H
#define FRONT_OR_H


#include "Logical.h"

class Or : public Logical{
public:
    Or(Token *tok, Expr *x1, Expr *x2);
    void jumping(int t, int f);
};


#endif //FRONT_OR_H
