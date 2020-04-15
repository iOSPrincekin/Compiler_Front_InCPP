//
// Created by LEE on 4/14/20.
//

#include "Op.h"
#include "Temp.h"

Op::Op(Token *tok, Type p):Expr(tok,p) {

}

Expr* Op::reduce() {
    Expr* x = gen();
    Temp* t = new Temp(type);
    emit( t->toString() + " = " + x->toString() );
    return t;
}