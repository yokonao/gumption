#include "item.h"
#include "linked_list.h"
#include "free_list.h"
#include <cassert>
#include <iostream>
#include <string>

void splice(Item *a, Item *b, Item *t)
{
    // aがvalidなLinkedListに所属しているか
    Item *tmp = a->next;
    while (!tmp->isDummy)
    {
        assert(tmp != a);
        tmp = tmp->next;
    }
    // 同リスト内に[a...b]が存在し、tが含まれない
    tmp = a;
    while (tmp != b)
    {
        assert(!tmp->isDummy);
        assert(tmp != t);
        tmp = tmp->next;
    }

    Item *ap = a->prev;
    Item *bp = b->next;
    ap->next = bp;
    bp->prev = ap;

    Item *tp = t->next;
    b->next = tp;
    a->prev = t;
    t->next = a;
    tp->prev = b;
};

LinkedList::LinkedList()
{
    Item m_head;
}

Item *LinkedList::head() { return &m_head; }

bool LinkedList::isEmpty() { return m_head.next == &m_head; }

Item *LinkedList::first()
{
    assert(!isEmpty());
    return m_head.next;
}

Item *LinkedList::last()
{
    assert(!isEmpty());
    return m_head.prev;
}

void LinkedList::debug()
{
    if (isEmpty())
    {
        std::cout << "This list is empty" << std::endl;
    }
    else
    {
        Item *tmp = head()->next;
        std::string result;
        while (!tmp->isDummy)
        {
            result += std::to_string(tmp->e);
            result += ',';
            tmp = tmp->next;
        }
        std::cout << result << std::endl;
    }
}

void LinkedList::moveAfter(Item *b, Item *ap)
{
    splice(b, b, ap);
}

void LinkedList::remove(Item *b)
{
    moveAfter(b, FreeList::head());
}

Item *LinkedList::insertAfter(int x, Item *a)
{
    FreeList::check();
    Item *ap = FreeList::first();
    moveAfter(ap, a);
    ap->e = x;
    return ap;
}

void LinkedList::moveToFront(Item *b)
{
    moveAfter(b, &m_head);
}

void LinkedList::moveToBack(Item *b)
{
    moveAfter(b, last());
}

void LinkedList::popFront()
{
    remove(first());
};

void LinkedList::popBack()
{
    remove(last());
}

Item *LinkedList::insertBefore(int x, Item *b)
{
    return insertAfter(x, b->prev);
}

void LinkedList::pushFront(int x)
{
    insertAfter(x, head());
}

void LinkedList::pushBack(int x)
{
    insertAfter(x, last());
}

void LinkedList::makeEmpty()
{
    splice(first(), last(), FreeList::last());
};
