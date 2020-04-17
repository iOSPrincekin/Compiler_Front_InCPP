//
// Created by LEE on 4/13/20.
//

#include "Id.h"
Id::Id(Word* id,Type* p, int b):Expr(id,p){
    offset = b;
}