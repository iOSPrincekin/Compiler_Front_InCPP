//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_ARRAY_H
#define FRONT_ARRAY_H


#include "Type.h"

class Array: public Type {
public:
    Type *of;      // array *of* type
    int size = 1;             // number of elements
    Array(int sz,Type* p);
    string toString();
};


#endif //FRONT_ARRAY_H
