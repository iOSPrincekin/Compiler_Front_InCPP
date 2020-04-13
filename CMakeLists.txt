cmake_minimum_required(VERSION 3.9)
project(Front)

set(CMAKE_CXX_STANDARD 11)

add_executable(Front main.cpp lexer/Tag.cpp lexer/Tag.h lexer/Token.cpp lexer/Token.h lexer/Word.cpp lexer/Word.h lexer/Real.cpp lexer/Real.h lexer/Num.cpp lexer/Num.h lexer/Lexer.cpp lexer/Lexer.h lexer/Hashtable.cpp lexer/Hashtable.h symbols/Type.cpp symbols/Type.h parser/Parser.cpp parser/Parser.h symbols/Env.cpp symbols/Env.h Inter/Access.cpp Inter/Access.h Inter/Node.cpp Inter/Node.h Inter/Expr.cpp Inter/Expr.h Inter/Id.cpp Inter/Id.h Inter/If.cpp Inter/If.h Inter/Stmt.cpp Inter/Stmt.h Inter/Logical.cpp Inter/Logical.h)