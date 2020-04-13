//
// Created by LEE on 4/12/20.
//

#include "Real.h"
Real::Real(float v):Token(v){
    value = v;
}

string Real::toString() {
    std::string s = std::to_string(value);
    return s;
}