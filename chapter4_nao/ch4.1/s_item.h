#ifndef S_ITEM_HPP
#define S_ITEM_HPP

struct SItem
{
    int e;
    SItem *next;
    bool isDummy;

    SItem();

    SItem(int e, SItem *next);
};

#endif
