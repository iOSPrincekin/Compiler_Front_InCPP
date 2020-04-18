//
// Created by LEE on 4/14/20.
//

#include "Constant.h"
#include "../lexer/Num.h"
Constant
        *const Constant::True  = new Constant(Word::_True,Type::Bool),
        *const Constant::False = new Constant(Word::_False,Type::Bool);
Constant::Constant(Token *tok, Type* p):Expr(tok,p) {

}

Constant::Constant(int i) :Expr(new Num(i),Type::Int){

}

void Constant::jumping(int t, int f) {
    if ( this == Constant::True && t != 0 ) emit("goto L" + std::to_string(t));
    else if ( this == Constant::False && f != 0) emit("goto L" + std::to_string(f));
}