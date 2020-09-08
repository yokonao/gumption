#ifndef ITEM_HPP
#define ITEM_HPP

template <typename T>
struct Item
{
    T e;
    Item *prev;
    Item *next;

    Item();

    Item(T e, Item *prev, Item *next);
};

#endif
