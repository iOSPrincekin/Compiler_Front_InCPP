//
// Created by LEE on 4/14/20.
//

#include "Break.h"
#include "Stmt.h"

Break::Break() {
    if( Stmt_Enclosing == Stmt_Null ) error("unenclosed break");
    stmt = Stmt_Enclosing;
}