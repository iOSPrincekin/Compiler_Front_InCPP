//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_BREAK_H
#define FRONT_BREAK_H


#include "Stmt.h"

class Break: public Stmt {
private:
    Stmt* stmt;
public:
    Break();
    void gen(int b, int a);
};


#endif //FRONT_BREAK_H
