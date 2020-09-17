#ifndef FREE_LIST_HPP
#define FREE_LIST_HPP

#include "item.h"
#include "linked_list.h"

class FreeList
{
private:
    static LinkedList m_LinkedList;

public:
    static Item *head();
    static bool isEmpty();
    static Item *first();
    static void check();
};

#endif
