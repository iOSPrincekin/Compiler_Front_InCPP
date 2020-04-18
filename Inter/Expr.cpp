//
// Created by LEE on 4/13/20.
//

#include "Expr.h"
Expr::Expr(Token *tok, Type* p):type(p){
    op = tok;
}
Expr* Expr::gen() { return this; }

Expr* Expr::reduce() { return this; }

void Expr::jumping( int t, int f)
{
    emitjumps(toString(), t, f);
}
void Expr::emitjumps(string test, int t, int f) {
    if (t !=0 && f !=0)
    {
        emit("if" + test + " goto L" + std::to_string(t));
        emit("goto L"+ std::to_string(f));
    }
    else if(t != 0)emit("if "+test+ " goto L" +std::to_string(t));
    else if(f != 0)emit("iffalse " + test + " goto L" +std::to_string(f));
    else;   /* nothing since both t and f fall through */

}

string Expr::toString() { return op->toString();}