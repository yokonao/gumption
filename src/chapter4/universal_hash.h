#ifndef UNIVERSAL_HASH_HPP
#define UNIVERSAL_HASH_HPP

#include <string>
#include <uarray.h>
#include <s_linked_list.h>
#include <hash_family.h>

using SLL = SLinkedList<std::string, std::string>;
using SI = SItem<std::string, std::string>;

class UniversalHash
{
    const int beta = 2;
    const int alpha = 4;
    int m = 257;
    int w = 8;
    int n = 0;
    SLL *t;
    HashFamily<std::string> *hashFamily;
    int hash(std ::string s);
    void reallocate(int mp);
    int findK(int m);
    int findPrime(int k);

public:
    UniversalHash();
    void insert(std::string s, std::string value);
    void remove(std::string s);
    std::string find(std::string s);
    std::string operator[](std::string s);
};
#endif
