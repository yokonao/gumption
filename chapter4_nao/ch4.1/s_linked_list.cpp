#include <cassert>
#include <iostream>
#include "s_linked_list.h"
#include "s_free_list.h"

void splice(SItem *ap, SItem *b, SItem *t)
{
    // apがvalidなLinkedListに所属しているか
    SItem *tmp = ap->next;
    while (!tmp->isDummy)
    {
        assert(tmp != ap);
        tmp = tmp->next;
    }
    // 同リスト内に[a...b]が存在し、tが含まれない
    tmp = ap->next;
    while (tmp != b)
    {
        assert(!tmp->isDummy);
        assert(tmp != t);
        tmp = tmp->next;
    }

    SItem *a = ap->next;
    ap->next = b->next;
    SItem *tp = t->next;
    b->next = tp;
    t->next = a;
};

SLinkedList::SLinkedList()
{
    SItem m_head;
}

SItem *SLinkedList::head() { return &m_head; }

bool SLinkedList::isEmpty() { return &m_head == m_head.next; }

SItem *SLinkedList::first()
{
    assert(!isEmpty());
    return m_head.next;
}

SItem *SLinkedList::last()
{
    assert(!isEmpty());
    return m_last;
}

std::string SLinkedList::all()
{
    if (isEmpty())
    {
        return "[]";
    }
    else
    {
        SItem *tmp = first();
        std::string result;
        while (!tmp->isDummy)
        {
            result += tmp->e;
            result += ',';
            tmp = tmp->next;
        }
        return result;
    }
}

SItem *SLinkedList::insertAfter(std::string x, SItem *a)
{
    SFreeList::check();
    SItem *ap = SFreeList::head();
    splice(ap, ap->next, a);
    a->next->e = x;
    if (a->next->next->isDummy)
    {
        m_last = a->next;
    }
    return a->next;
}

void SLinkedList::pushBack(std::string x)
{
    if (isEmpty())
    {
        insertAfter(x, head());
    }
    else
    {
        insertAfter(x, last());
    }
}

void SLinkedList::removeAfter(SItem *bp)
{
    SItem *b = bp->next;
    assert(!b->isDummy);
    splice(bp, b, SFreeList::head());
    if (bp->next->isDummy)
    {
        m_last = bp;
    }
}
