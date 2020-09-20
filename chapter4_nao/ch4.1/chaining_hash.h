#ifndef CHAINING_HASH_HPP
#define CHAINING_HASH_HPP

#include "s_linked_list.h"

class ChainingHash
{
    const int beta = 2;
    const int alpha = 4;
    int m = 1;
    int n = 0;
    SLinkedList *t;

public:
    ChainingHash();
    void insert(std::string e);
    void remove(std::string key);
    std::string find(std::string key);
};

#endif
