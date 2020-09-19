#include <cassert>
#include "s_linked_list.h"

void splice(SItem *ap, SItem *b, SItem *t)
{
}

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
