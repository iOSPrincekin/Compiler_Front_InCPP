//
// Created by LEE on 4/12/20.
//

#ifndef FRONT_HASHTABLE_H
#define FRONT_HASHTABLE_H

#include <string>
#include <map>
#include "/usr/local/Cellar/boost/1.67.0_1/include/boost/variant.hpp"
#include "Token.h"
#include "Word.h"

using namespace std;
class Hashtable {
private:
  //  int table_size;
    using Key = boost::variant<Word*,Token*, std::string>;
    map<Key,void *> hashtable;
public:
   Hashtable();
    void put(Key key,void * value);

    void* get(Key key);
};


#endif //FRONT_HASHTABLE_H
