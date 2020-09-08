#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct LL
{
    int data;
    LL *prev;
    LL *next;

    LL();

    LL(int data, LL *prev, LL *next);
};

#endif
