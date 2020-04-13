//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_REAL_H
#define FRONT_REAL_H
#include "Token.h"

class Real: public Token{
public:
    Real(float v);
    float value;
    string toString();
};


#endif //FRONT_REAL_H
