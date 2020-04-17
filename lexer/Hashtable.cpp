//
// Created by LEE on 4/12/20.
//

#include "Hashtable.h"
Hashtable::Hashtable() {
    hashtable = map<Key,void *>();
}
void Hashtable::put(Key key, void* value) {
   hashtable[key] = value;
}

void* Hashtable::get(Key key) {
    return  hashtable[key];
}