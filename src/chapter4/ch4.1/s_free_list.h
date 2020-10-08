#ifndef S_FREE_LIST_HPP
#define S_FREE_LIST_HPP

#include "s_item.h"
#include "s_linked_list.h"

class SFreeList
{
private:
    static SLinkedList m_SLinkedList;

public:
    static SItem *head();
    static bool isEmpty();
    static SItem *first();
    static SItem *last();
    static void check();
    static void clear();
};

#endif
