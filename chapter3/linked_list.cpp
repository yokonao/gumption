#include "item.h"
#include "linked_list.h"


LinkedList::LinkedList(){
    Item m_head;
}

Item *LinkedList::head() { return &m_head; }

bool LinkedList::isEmpty() { return m_head.next == &m_head; }
