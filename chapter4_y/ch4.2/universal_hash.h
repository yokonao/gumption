#ifndef UNIVERSAL_HASH_HPP
#define UNIVERSAL_HASH_HPP

#include "s_linked_list.h"

extern std::string key(std::string e);

extern std::string element(std::string key);

extern long long hashRand(std::string key);

extern int hash(std::string key, int mod);

class UniversalHash
{
    const int beta = 2;
    const int alpha = 4;
    int m = 257;
    int w = 2;
    int n = 0;
    SLinkedList *t;

    void reallocate(int mp);

public:
    UniversalHash();
    void insert(std::string e, std::string value);
    void remove(std::string key);
    std::string find(std::string key);
    std::string operator[](std::string key);
};

#endif
