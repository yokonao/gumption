#include "free_list.h"

LinkedList FreeList::m_LinkedList;

Item *FreeList::head() { return m_LinkedList.head(); }

bool FreeList::isEmpty() { return m_LinkedList.isEmpty(); }

Item *FreeList::first() { return m_LinkedList.first(); }

Item *FreeList::last() { return m_LinkedList.last(); }

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

void FreeList::clear()
{
    Item *head = m_LinkedList.head();
    Item *tmp = head->next;
    while (!tmp->isDummy)
    {
        Item *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head->next = head;
    head->prev = head;
}
