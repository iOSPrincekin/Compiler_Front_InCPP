//
// Created by LEE on 4/14/20.
//

#ifndef FRONT_TEMP_H
#define FRONT_TEMP_H


#include "Expr.h"

class Temp: public Expr {
public:

    int number = 0;

    Temp(Type p);

    string toString();



};
static int Temp_count = 0;


#endif //FRONT_TEMP_H
