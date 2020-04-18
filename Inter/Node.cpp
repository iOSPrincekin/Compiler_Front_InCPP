//
// Created by LEE on 4/13/20.
//

#include "Node.h"
#include "../lexer/Lexer.h"
#include <stdexcept>
#include <iostream>
Node::Node() {
    //lexline = Lexer::line;

}

void Node::error(string s) {
    throw std::domain_error(s);
}

int Node::newlabel() { return ++labels;}

void Node::emitlabel(int i) {cout << "L" << i << ":" << endl;}
void Node::emit(string s) {cout << "\t" + s << endl;}