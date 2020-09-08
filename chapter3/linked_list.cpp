#include "linked_list.h"

LL::LL()
{
}

LL::LL(int data, LL prev, LL next)
{
    this->data = data;
    this->prev = &prev;
    this->next = &next;
}
