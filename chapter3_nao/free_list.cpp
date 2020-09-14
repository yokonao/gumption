#include "free_list.h"

LinkedList FreeList::m_LinkedList;

Item *FreeList::head() { return m_LinkedList.head(); }

bool FreeList::isEmpty() { return m_LinkedList.isEmpty(); }

Item *FreeList::first() { return m_LinkedList.first(); }

void FreeList::check()
{
    // 空ならば要素を追加する
    if (m_LinkedList.isEmpty())
    {
        Item *h = m_LinkedList.head();
        Item *a = new Item(0, h, h);
        h->next = a;
        h->prev = a;
    }
}
