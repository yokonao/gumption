#include "item.h"
#include "linked_list.h"
#include <cassert>

LinkedList::LinkedList()
{
    Item m_head;
}

Item *LinkedList::head() { return &m_head; }

bool LinkedList::isEmpty() { return m_head.next == &m_head; }

Item *LinkedList::first()
{
    assert(!isEmpty);
    return m_head.next;
}

Item *LinkedList::last()
{
    assert(!isEmpty);
    return m_head.prev;
}
