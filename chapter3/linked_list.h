#ifndef Linked_LIST_HPP
#define Linked_LIST_HPP

#include "item.h"

class LinkedList
{
    Item m_head;

public:
    LinkedList();

    Item *head();
    bool isEmpty();
    Item *first();
    Item *last();
    void debug();
};

#endif
