#include "s_free_list.h"

SLinkedList SFreeList::m_SLinkedList;

SItem *SFreeList::head() { return m_SLinkedList.head(); }

bool SFreeList::isEmpty() { return m_SLinkedList.isEmpty(); }

SItem *SFreeList::first() { return m_SLinkedList.first(); }

SItem *SFreeList::last() { return m_SLinkedList.last(); }

void SFreeList::check()
{
    // 空ならば要素を追加する
    if (m_SLinkedList.isEmpty())
    {
        SItem *h = m_SLinkedList.head();
        SItem *a = new SItem("", h);
        h->next = a;
    }
}

void SFreeList::clear()
{
    SItem *head = m_SLinkedList.head();
    SItem *tmp = head->next;
    while (!tmp->isDummy)
    {
        SItem *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head->next = head;
}
