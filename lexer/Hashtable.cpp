//
// Created by LEE on 4/12/20.
//

#include "Hashtable.h"
Hashtable::Hashtable() {
}
void Hashtable::put(string key, void* value) {
   hashtable[key] = value;
}

void* Hashtable::get(string key) {
    return  hashtable[key];
}