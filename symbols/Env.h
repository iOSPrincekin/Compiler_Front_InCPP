//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_ENV_H
#define FRONT_ENV_H

#include "../lexer/Hashtable.h"
#include "../Inter/Id.h"

class Env {
private:
    Hashtable table;
protected:
    Env *prev;
public:
    Env(Env* n);
    void put(Token w, Id* i);
    Id* get(Token w);
};


#endif //FRONT_ENV_H
