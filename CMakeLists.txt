cmake_minimum_required(VERSION 3.9)
project(Front)

set(CMAKE_CXX_STANDARD 11)

############# boost

find_package(Boost 1.67.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
   # message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()


add_executable(Front main.cpp lexer/Tag.cpp lexer/Tag.h lexer/Token.cpp lexer/Token.h lexer/Word.cpp lexer/Word.h lexer/Real.cpp lexer/Real.h lexer/Num.cpp lexer/Num.h lexer/Lexer.cpp lexer/Lexer.h lexer/Hashtable.cpp lexer/Hashtable.h symbols/Type.cpp symbols/Type.h parser/Parser.cpp parser/Parser.h symbols/Env.cpp symbols/Env.h Inter/Access.cpp Inter/Access.h Inter/Node.cpp Inter/Node.h Inter/Expr.cpp Inter/Expr.h Inter/Id.cpp Inter/Id.h Inter/If.cpp Inter/If.h Inter/Stmt.cpp Inter/Stmt.h Inter/Logical.cpp Inter/Logical.h)

if(Boost_FOUND)

    target_link_libraries(Front ${Boost_LIBRARIES})

endif()