//
// Created by LEE on 4/14/20.
//

#include "Temp.h"

Temp::Temp(Type* p):Expr(Word::_temp,p) {
     number = ++Temp_count;
}

string Temp::toString() {
    return "t" + std::to_string(number);
}