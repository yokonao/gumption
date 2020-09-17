#ifndef ITEM_HPP
#define ITEM_HPP

struct Item
{
    int e;
    Item *prev;
    Item *next;
    bool isDummy;

    Item();

    Item(int e, Item *prev, Item *next);
};

#endif
