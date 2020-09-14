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

    // Basic Procedures
    void moveAfter(Item *b, Item *ap);

    void remove(Item *b);

    Item *insertAfter(int x, Item *a);

    void concat(LinkedList Lp);

    // Advanced Procedures
    void moveToFront(Item *b);

    void moveToBack(Item *b);

    void popFront();

    void popBack();

    Item *insertBefore(int x, Item *b);

    void pushFront(int x);

    void pushBack(int x);

    void makeEmpty();
};

#endif
