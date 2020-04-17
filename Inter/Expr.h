//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_EXPR_H
#define FRONT_EXPR_H


#include "Node.h"
#include "../lexer/Token.h"
#include "../symbols/Type.h"

class Expr: public Node {
public:
    Token *op;
    Type *type;

    Expr(Token *tok, Type* p);

    Expr* gen();

    Expr* reduce();

    virtual void jumping( int t, int f);
    void emitjumps(string test, int t, int f);
    string toString();




};


#endif //FRONT_EXPR_H
