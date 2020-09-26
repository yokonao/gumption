#ifndef CHAINING_HASH_HPP
#define CHAINING_HASH_HPP

#include "s_linked_list.h"

std::string key(std::string e);

std::string element(std::string key);

long long hashPrime(std::string key);

int hash(std::string key, int mod);

class ChainingHash
{
    const int beta = 2;
    const int alpha = 4;
    int m = 1;
    int n = 0;
    SLinkedList *t;

    void reallocate(int mp);

public:
    ChainingHash();
    void insert(std::string e, std::string value);
    void remove(std::string key);
    std::string find(std::string key);
    std::string operator[](std::string key);
};

#endif
