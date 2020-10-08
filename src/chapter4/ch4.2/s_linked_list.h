#ifndef S_Linked_LIST_HPP
#define S_Linked_LIST_HPP

#include "s_item.h"

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

    SItem *insertAfter(std::string e, std::string value, SItem *a);

    void pushBack(std::string e, std::string value);

    void removeAfter(SItem *bp);
};

#endif
