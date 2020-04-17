//
// Created by LEE on 4/13/20.
//

#include "Access.h"

Access::Access(Id *a, Expr *i, Type p):Op(new Word("[]",Tag::INDEX),p) {
    array = a;
    index = i;
}

Expr Access::gen() {
    return  Access(array, index->reduce(), type);
}
void Access::jumping(int t, int f) {
    emitjumps(reduce()->toString(),t,f);
}

string Access::toString() {
    return array->toString() + " [ " + index->toString() + " ]";
}