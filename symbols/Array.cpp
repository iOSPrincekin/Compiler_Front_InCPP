//
// Created by LEE on 4/14/20.
//

#include "Array.h"

Array::Array(int sz, Type p):Type("[]",Tag::INDEX,sz*p.width),of(p){
    size = sz;
}

string Array::toString() {
    return "[" + std::to_string(size) + "] " + of.toString();
}