//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_OP_H
#define FRONT_OP_H


#include "Expr.h"

class Op: public Expr {
public:

    Op(Token *tok, Type* p);
    Expr* reduce() ;

};


#endif //FRONT_OP_H
