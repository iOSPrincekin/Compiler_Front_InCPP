//
// Created by LEE on 4/12/20.
//

#include "Num.h"
#include "Tag.h"
Num::Num(int v):Token(Tag::NUM) {
   value = v;
}
string Num::toString() {

    std::string s = std::to_string(value);
    return s;
}