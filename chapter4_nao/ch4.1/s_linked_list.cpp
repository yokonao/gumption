#include <cassert>
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
    m_last = &m_head;
}

SItem *SLinkedList::head() { return &m_head; }

bool SLinkedList::isEmpty() { return &m_head == m_head.next; }

SItem *SLinkedList::first() { return m_head.next; }

SItem *SLinkedList::last() { return m_last; }

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
            result += std::to_string(tmp->e);
            result += ',';
            tmp = tmp->next;
        }
        return result;
    }
}

SItem *SLinkedList::insertAfter(int x, SItem *a)
{
    SFreeList::check();
    SItem *ap = SFreeList::head();
    splice(ap, ap->next, a);
    a->next->e = x;
    return a->next;
}
