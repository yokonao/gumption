#include "item.h"

Item::Item()
{
    prev = this;
    next = this;
    isDummy = true;
}

Item::Item(int e, Item *prev, Item *next)
{
    this->e = e;
    this->prev = prev;
    this->next = next;
    isDummy = false;
}
