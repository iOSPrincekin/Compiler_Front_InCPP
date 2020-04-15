//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_STMT_H
#define FRONT_STMT_H


#include "Node.h"

class Stmt: public Node {
public:
    Stmt();

    void gen(int b, int a);  // called with labels begin and after
    int after = 0;           // saves label after


};
static Stmt* Stmt_Null = new Stmt();
static Stmt* Stmt_Enclosing = Stmt_Null;



#endif //FRONT_STMT_H
