#ifndef Linked_LIST_HPP
#define Linked_LIST_HPP

#include "s_item.h"
#include <string>

class SLinkedList
{
    SItem m_head;
    SItem *m_last;

public:
    SLinkedList();

    SItem *head();
    bool isEmpty();
    SItem *first();
    SItem *last();

    // For Debug
    std::string all();

    SItem *insertAfter(int x, SItem *a);

    void pushBack(int x);
};

#endif
