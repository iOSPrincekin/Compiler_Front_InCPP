//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_NUM_H
#define FRONT_NUM_H


#include "Token.h"

class Num : public Token {
public:
    int value;
    Num(int v);
    virtual string toString();
};


#endif //FRONT_NUM_H
