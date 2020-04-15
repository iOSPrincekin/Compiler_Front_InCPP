//
// Created by LEE on 4/14/20.
//

#include "Constant.h"
#include "../lexer/Num.h"

Constant::Constant(Token *tok, Type p):Expr(tok,p) {

}

Constant::Constant(int i) :Expr(new Num(i),Type_Int){

}

void Constant::jumping(int t, int f) {
    if ( this == Constant_True && t != 0 ) emit("goto L" + t);
    else if ( this == Constant_False && f != 0) emit("goto L" + f);
}