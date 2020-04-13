//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_HASHTABLE_H
#define FRONT_HASHTABLE_H

#include <string>
#include <map>
#include "Token.h"
using namespace std;
class Hashtable {
private:
    int table_size;
    map<string,void *> hashtable;
public:
   Hashtable();
    void put(string key,void * value);

    void* get(string key);
};


#endif //FRONT_HASHTABLE_H
