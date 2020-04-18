//
// Created by LEE on 4/12/20.
//

#include "Real.h"
#include "Tag.h"

Real::Real(float v):Token(Tag::REAL){
    value = v;
}

string Real::toString() {
    std::string s = std::to_string(value);
    return s;
}