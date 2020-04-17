//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_ACCESS_H
#define FRONT_ACCESS_H


#include "Id.h"
#include "Op.h"

class Access: public Op {
public:
    Id *array;
    Expr *index;
    Access(Id *a, Expr *i, Type* p);
    Expr gen();
    void jumping(int t,int f);
    string toString();

};


#endif //FRONT_ACCESS_H
