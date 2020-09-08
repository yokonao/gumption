#include "item.h"

template <class T>
Item<T>::Item()
{
}

template <class T>
Item<T>::Item(T e, Item *prev, Item *next){
    this->e = e;
    this->prev = prev;
    this->next = next;
}

template Item<int>::Item();
template Item<int>::Item(int e, Item *prev, Item *next); 
