//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_SEQ_H
#define FRONT_SEQ_H


#include "Stmt.h"

class Seq: public Stmt {
    Stmt *stmt1; Stmt* stmt2;
public:
    Seq(Stmt *s1, Stmt *s2);
    void gen(int b, int a);
};


#endif //FRONT_SEQ_H
