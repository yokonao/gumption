#include <iostream>
#include <cassert>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"

void testSItem()
{
    SItem dummy;
    assert(dummy.isDummy);
    assert(dummy.e == 0);
    assert(dummy.next == &dummy);
    SItem item(1, &dummy);
    dummy.next = &item;
    assert(item.e == 1);
    assert(item.next == &dummy);
    assert(dummy.next == &item);
}

void testSLinkedListDefaultConstructor()
{
    SLinkedList sll;
    assert(sll.isEmpty());
    assert(sll.head()->isDummy);
    assert(sll.all() == "[]");
}

void testSFreeList()
{
    assert(SFreeList::isEmpty());
    SFreeList::check();
    assert(!SFreeList::isEmpty());
    SFreeList::clear();
    assert(SFreeList::isEmpty());
}

void testInsertAfter()
{
    SLinkedList sll;
    assert(sll.isEmpty());
    SItem *one = sll.insertAfter(1, sll.head());
    assert(sll.all() == "1,");
    assert(one == sll.head()->next);
    assert(one->next == sll.head());
    SItem *two = sll.insertAfter(2, one);
    std::cout << sll.all() << std::endl;
    assert(sll.all() == "1,2,");
    SItem *three = sll.insertAfter(3, sll.head());
    assert(sll.all() == "3,1,2,");
}

int main()
{
    std::cout << "TEST START" << std::endl;
    testSItem();
    testSLinkedListDefaultConstructor();
    testSFreeList();
    testInsertAfter();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
