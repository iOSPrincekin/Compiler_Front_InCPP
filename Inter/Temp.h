//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_TEMP_H
#define FRONT_TEMP_H


#include "Expr.h"

class Temp: public Expr {
public:
    static int count;
    int number = 0;

    Temp(Type p);

    string toString();



};


#endif //FRONT_TEMP_H
