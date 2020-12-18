#ifndef UNIVERSAL_HASH_HPP
#define UNIVERSAL_HASH_HPP

#include <string>
#include <uarray.h>
#include <s_linked_list.h>
#include <hash_family_one_universal.h>

class UniversalHash
{
    const int beta = 2;
    const int alpha = 4;
    int m = 257;
    int w = 8;
    int n = 0;
    SLinkedList *t;
    HashFamily_OneUniversal *hashFunction;
    void reallocate(int mp);

public:
    UniversalHash();
    void insert(std::string s, std::string value);
    void remove(std::string s);
    std::string find(std::string s);
    std::string operator[](std::string s);
};
#endif
