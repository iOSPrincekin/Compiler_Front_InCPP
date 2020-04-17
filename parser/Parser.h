//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_PARSER_H
#define FRONT_PARSER_H


#include "../lexer/Lexer.h"
#include "../symbols/Env.h"
#include "../Inter/Stmt.h"
#include "../Inter/Access.h"

class Parser {
private:
    Lexer* lex;  // lexial analyzer for this parser
    Token* look;  // lookahead tagen
    Env* top = nullptr; // current or top symbol table
    int used = 0;         // storage used for declarations

public:
    Parser(Lexer* l);
    void move();
    void error(string s);
    void match(int t);
    void program();
    Stmt* block();
    void decls();
    Type* type();
    Type* dims(Type* p);
    Stmt* stmts();
    Stmt* stmt();
    Stmt* assign();
    Expr* _bool();
    Expr* join();
    Expr* equality();
    Expr* rel();
    Expr* expr();
    Expr* term();
    Expr* unary();
    Expr* factor();
    Access* offset(Id* a);
};


#endif //FRONT_PARSER_H
