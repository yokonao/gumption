#include "s_item.h"

SItem::SItem()
{
    next = this;
    isDummy = true;
}

SItem::SItem(std::string e, std::string value, SItem *next)
{
    this->e = e;
    this->value = value;
    this->next = next;
    isDummy = false;
}
