//
// Created by LEE on 4/14/20.
//

#include "Arith.h"
Arith::Arith(Token* tok, Expr *x1, Expr *x2):Op(tok, Type_NULL) {
    expr1 = x1;
    expr2 = x2;
    type = Type::max(expr1->type,expr2->type);

}