//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_TOKEN_H
#define FRONT_TOKEN_H

#include <string>
using namespace std;
class Token {
public:
    Token(int t);
    int tag;
    virtual string toString();

};


#endif //FRONT_TOKEN_H
