//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_ID_H
#define FRONT_ID_H


#include "Expr.h"

class Id: public Expr {
public:
    int offset;  // relative address
    Id(Word* id,Type p, int b);
};


#endif //FRONT_ID_H
