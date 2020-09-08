#ifndef Linked_LIST_HPP
#define Linked_List_HPP

#include "item.h"

class LinkedList
{
    Item<int> m_head;

public:
    LinkedList();

    Item<int> *head();
    bool isEmpty();

};

#endif
