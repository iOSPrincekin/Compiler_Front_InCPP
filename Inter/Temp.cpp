//
// Created by LEE on 4/14/20.
//

#include "Temp.h"

Temp::Temp(Type p):Expr((Token*)&Word_temp,p) {

}

string Temp::toString() {
    return "t" + std::to_string(number);
}