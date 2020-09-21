#include <iostream>
#include <cassert>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"

void testSItem()
{
    SItem dummy;
    assert(dummy.isDummy);
    assert(dummy.e == "");
    assert(dummy.next == &dummy);
    SItem item("a", "", &dummy);
    dummy.next = &item;
    assert(item.e == "a");
    assert(item.next == &dummy);
    assert(dummy.next == &item);
    SItem item2("abcd", "", &dummy);
    dummy.next = &item;
    assert(item2.e == "abcd");
    assert(item2.next == &dummy);
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
    SItem *ruby = sll.insertAfter("Ruby", sll.head());
    assert(sll.all() == "Ruby,");
    assert(ruby == sll.head()->next);
    assert(ruby->next == sll.head());
    SItem *python = sll.insertAfter("Python", ruby);
    assert(sll.all() == "Ruby,Python,");
    SItem *php = sll.insertAfter("PHP", sll.head());
    assert(sll.all() == "PHP,Ruby,Python,");
}

void testPushBack()
{
    SLinkedList sll;
    assert(sll.isEmpty());
    sll.pushBack("Java");
    assert(sll.all() == "Java,");
    sll.pushBack("C++");
    assert(sll.all() == "Java,C++,");
    sll.pushBack("C#");
    assert(sll.all() == "Java,C++,C#,");
}

void testRemoveAfter()
{
    SLinkedList sll;
    assert(sll.isEmpty());
    SItem *dart = sll.insertAfter("Dart", sll.head());
    assert(sll.all() == "Dart,");
    assert(dart == sll.head()->next);
    assert(dart->next == sll.head());
    SItem *swift = sll.insertAfter("Swift", dart);
    assert(sll.all() == "Dart,Swift,");
    SItem *kotlin = sll.insertAfter("Kotlin", sll.head());
    assert(sll.all() == "Kotlin,Dart,Swift,");
    sll.removeAfter(sll.head());
    assert(sll.all() == "Dart,Swift,");
    sll.removeAfter(dart);
    assert(sll.all() == "Dart,");
    sll.removeAfter(sll.head());
    assert(sll.isEmpty());
}

int main()
{
    std::cout << "TEST START" << std::endl;
    testSItem();
    testSLinkedListDefaultConstructor();
    testSFreeList();
    testInsertAfter();
    testPushBack();
    testRemoveAfter();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
