//
// Created by LEE on 4/13/20.
//

#include "Parser.h"
#include "../symbols/Array.h"
#include "../lexer/Num.h"
#include "../Inter/Seq.h"
#include "../Inter/If.h"
#include "../Inter/SetElem.h"
#include "../Inter/Set.h"
#include "../Inter/Or.h"
#include "../Inter/And.h"
#include "../Inter/Rel.h"
#include "../Inter/Arith.h"
#include "../Inter/Unary.h"
#include "../Inter/Not.h"
#include "../Inter/Else.h"
#include "../Inter/While.h"
#include "../Inter/Do.h"
#include "../Inter/Break.h"
#include "../Inter/Constant.h"


Parser::Parser(Lexer* l) {

    lex = l;
    move();
}
void Parser::move() {
    look = lex->scan();
}

void Parser::error(string s) {
    throw std::domain_error("near line "+std::to_string(lex->line)+": "+s+"\n");
}

void Parser::match(int t) {
    if( look->tag == t ) move();
    else error("syntax error");
}

void Parser::program() {
    Stmt* s = block();
    int begin = s->newlabel();  int after = s->newlabel();
    s->emitlabel(begin);  s->gen(begin, after);  s->emitlabel(after);
}

Stmt* Parser::block() {
    match('{');  Env *savedEnv = top;  top = new Env(top);
    decls(); Stmt *s = stmts();
    match('}');  top = savedEnv;
    return s;
}


void Parser::decls() {
    while( look->tag == Tag::BASIC ) {   // D -> type ID ;
        Type *p = type(); Token *tok = look; match(Tag::ID); match(';');
        Id *id =  new Id(static_cast<Word *>(tok), p, used);
        top->put( tok, id );
        used = used + p->width;
    }
}

Type* Parser::type() {
    Type* p =  static_cast<Type *>(look);            // expect look.tag == Tag.BASIC
    match(Tag::BASIC);
    if( look->tag != '[' ) return p; // T -> basic
    else return dims(p);            // return array type
}

Type* Parser::dims(Type* p) {
    match('[');  Token* tok = look;  match(Tag::NUM);  match(']');
    if( look->tag == '[' )
        p = dims(p);
    return new Array((static_cast<Num *>(tok))->value, p);
}

Stmt* Parser::stmts() {
    if ( look->tag == '}' ) return (Stmt*)Stmt::Null;
    else return new Seq(stmt(), stmts());
}

Stmt* Parser::stmt() {
        Expr *x;  Stmt *s, *s1, *s2;
        Stmt *savedStmt;         // save enclosing loop for breaks

        switch( look->tag ) {

            case ';': {
                move();
                return (Stmt*)Stmt::Null;

                break;

            }
            case Tag::IF: {
                match(Tag::IF);
                match('(');
                x = _bool();
                match(')');
                s1 = stmt();
                if (look->tag != Tag::ELSE) return new If(x, s1);
                match(Tag::ELSE);
                s2 = stmt();
                return new Else(x, s1, s2);

                break;

            }

            case Tag::WHILE: {
                While *whilenode = new While();
                savedStmt = (Stmt*)Stmt::Enclosing;
                Stmt::Enclosing = whilenode;
                match(Tag::WHILE);
                match('(');
                x = _bool();
                match(')');
                s1 = stmt();
                whilenode->init(x, s1);
                Stmt::Enclosing = savedStmt;  // reset Stmt.Enclosing
                return whilenode;

                break;
            }


            case Tag::DO: {
                Do *donode = new Do();
                savedStmt = (Stmt*)Stmt::Enclosing;
                Stmt::Enclosing = donode;
                match(Tag::DO);
                s1 = stmt();
                match(Tag::WHILE);
                match('(');
                x = _bool();
                match(')');
                match(';');
                donode->init(s1, x);
                Stmt::Enclosing = savedStmt;  // reset Stmt.Enclosing
                return donode;

                break;

            }

            case Tag::BREAK: {
                match(Tag::BREAK);
                match(';');
                return new Break();


                break;
            }

            case '{': {
                return block();

                break;
            }
            default: {
                return assign();
                break;
            }
        }


}

Stmt* Parser::assign() {
    Stmt* stmt;  Token* t = look;
    match(Tag::ID);
    Id *id = top->get(t);
    if( id == nullptr ) error(t->toString() + " undeclared");

    if( look->tag == '=' ) {       // S -> id = E ;
        move();  stmt = new Set(id, _bool());
    }
    else {                        // S -> L = E ;
        Access* x = offset(id);
        match('=');  stmt = new SetElem(x, _bool());
    }
    match(';');
    return stmt;
}

Expr* Parser::_bool() {
    Expr *x = join();
    while( look->tag == Tag::OR ) {
        Token *tok = look;  move();  x = new Or(tok, x, join());
    }
    return x;
}

Expr* Parser::join() {
    Expr* x = equality();
    while( look->tag == Tag::AND ) {
        Token *tok = look;  move();  x = new And(tok, x, equality());
    }
    return x;
}

Expr* Parser::equality() {
    Expr* x = rel();
    while( look->tag == Tag::EQ || look->tag == Tag::NE ) {
        Token *tok = look;  move();  x = new Rel(tok, x, rel());
    }
    return x;
}


Expr* Parser::rel() {
    Expr *x = expr();
    switch( look->tag ) {
        case '<': case Tag::LE: case Tag::GE: case '>': {
            Token *tok = look;
            move();
            return new Rel(tok, x, expr());
        }
        default:
            return x;
    }
}


Expr* Parser::expr() {
    Expr* x = term();
    while( look->tag == '+' || look->tag == '-' ) {
        Token *tok = look;  move();  x = new Arith(tok, x, term());
    }
    return x;
}

Expr* Parser::term() {
    Expr* x = unary();
    while(look->tag == '*' || look->tag == '/' ) {
        Token *tok = look;  move();   x = new Arith(tok, x, unary());
    }
    return x;
}

Expr* Parser::unary() {
    if( look->tag == '-' ) {
        move();  return new Unary(Word::_minus, unary());
    }
    else if( look->tag == '!' ) {
        Token *tok = look;  move();  return new Not(tok, unary());
    }
    else return factor();
}


Expr* Parser::factor() {
    Expr *x = nullptr;
    switch( look->tag ) {
        case '(':
            move(); x = _bool(); match(')');
            return x;

        case Tag::NUM:
            x = new Constant(look, Type::Int);    move(); return x;
        case Tag::REAL:
            x = new Constant(look, Type::Float);  move(); return x;
        case Tag::TRUE:
            x = Constant_True;                   move(); return x;
        case Tag::FALSE:
            x = Constant_False;                  move(); return x;
        default:
            error("syntax error");
            return x;
        case Tag::ID:
            string s = look->toString();
            Id *id = top->get(look);
            if( id == nullptr ) error(look->toString() + " undeclared");
            move();
            if( look->tag != '[' ) return id;
            else return offset(id);
    }

}

Access* Parser::offset(Id* a) {  // I -> [E] | [E] I
    Expr *i; Expr *w; Expr *t1, *t2; Expr *loc;  // inherit id

    Type *type = a->type;
    match('['); i = _bool(); match(']');     // first index, I -> [ E ]
    type = (dynamic_cast<Array*>(type))->of;
    w = new Constant(type->width);
    t1 = new Arith(new Token('*'), i, w);
    loc = t1;
    while( look->tag == '[' ) {      // multi-dimensional I -> [ E ] I
        match('['); i = _bool(); match(']');
        type = (dynamic_cast<Array*>(type))->of;
        w = new Constant(type->width);
        t1 = new Arith(new Token('*'), i, w);
        t2 = new Arith(new Token('+'), loc, t1);
        loc = t2;
    }

    return new Access(a, loc, type);
}
