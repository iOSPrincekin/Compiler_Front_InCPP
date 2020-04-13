//
// Created by LEE on 4/13/20.
//

#include "Env.h"
Env::Env(Env* n) {
  prev = n;
}

void Env::put(Token w, Id i) {
    //table.put(&w,&i);
}