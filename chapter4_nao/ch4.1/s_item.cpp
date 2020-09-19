#include "s_item.h"

SItem::SItem()
{
    next = this;
    isDummy = true;
}

SItem::SItem(int e, SItem *next)
{
    this->e = e;
    this->next = next;
    isDummy = false;
}
