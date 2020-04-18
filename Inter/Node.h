//
// Created by LEE on 4/13/20.
//

#ifndef FRONT_NODE_H
#define FRONT_NODE_H

#include <string>
using namespace std;
class Node {
public:
    int lexline = 0;
    Node();

    void error(string s);
    static int labels;


    int newlabel();
    void emitlabel(int i);
    void emit(string s);
};


#endif //FRONT_NODE_H
