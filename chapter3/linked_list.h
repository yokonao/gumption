#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LL
{
public:
    int data;
    LL *prev;
    LL *next;

    LL();

    LL(int data, LL prev, LL next);
};

#endif
