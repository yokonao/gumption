#include "item.h"
#include "linked_list.h"
#include <cassert>
#include <iostream>
#include <string>

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
