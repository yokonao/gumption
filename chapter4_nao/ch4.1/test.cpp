#include <iostream>
#include <cassert>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"
#include "chaining_hash.h"
#include "expectation.h"

void testSItem()
{
    SItem dummy;
    expect(dummy.isDummy).to_be_truthy();
    expect(dummy.e).to_be("");
    expect(dummy.next).to_be(&dummy);
    SItem item("a", "", &dummy);
    dummy.next = &item;
    expect(item.e).to_be("a");
    expect(item.next).to_be(&dummy);
    expect(dummy.next).to_be(&item);
    SItem item2("abcd", "", &dummy);
    dummy.next = &item;
    expect(item2.e).to_be("abcd");
    expect(item2.next).to_be(&dummy);
    expect(dummy.next).to_be(&item);
}

void testSLinkedListDefaultConstructor()
{
    SLinkedList sll;
    expect(sll.isEmpty()).to_be_truthy();
    expect(sll.head()->isDummy).to_be_truthy();
    expect(sll.all()).to_be("[]");
}

void testSFreeList()
{
    expect(SFreeList::isEmpty()).to_be_truthy();
    SFreeList::check();
    expect(SFreeList::isEmpty()).to_be_falsy();
    SFreeList::clear();
    expect(SFreeList::isEmpty()).to_be_truthy();
}

void testInsertAfter()
{
    SLinkedList sll;
    expect(sll.isEmpty()).to_be_truthy();
    SItem *ruby = sll.insertAfter("Ruby", sll.head());
    expect(sll.all()).to_be("Ruby,");
    expect(ruby).to_be(sll.head()->next);
    expect(ruby->next).to_be(sll.head());
    SItem *python = sll.insertAfter("Python", ruby);
    expect(sll.all()).to_be("Ruby,Python,");
    SItem *php = sll.insertAfter("PHP", sll.head());
    expect(sll.all()).to_be("PHP,Ruby,Python,");
}

void testPushBack()
{
    SLinkedList sll;
    expect(sll.isEmpty()).to_be_truthy();
    sll.pushBack("Java");
    expect(sll.all()).to_be("Java,");
    sll.pushBack("C++");
    expect(sll.all()).to_be("Java,C++,");
    sll.pushBack("C#");
    expect(sll.all()).to_be("Java,C++,C#,");
}

void testRemoveAfter()
{
    SLinkedList sll;
    expect(sll.isEmpty()).to_be_truthy();
    SItem *dart = sll.insertAfter("Dart", sll.head());
    expect(sll.all()).to_be("Dart,");
    expect(dart).to_be(sll.head()->next);
    expect(dart->next).to_be(sll.head());
    SItem *swift = sll.insertAfter("Swift", dart);
    expect(sll.all()).to_be("Dart,Swift,");
    SItem *kotlin = sll.insertAfter("Kotlin", sll.head());
    expect(sll.all()).to_be("Kotlin,Dart,Swift,");
    sll.removeAfter(sll.head());
    expect(sll.all()).to_be("Dart,Swift,");
    sll.removeAfter(dart);
    expect(sll.all()).to_be("Dart,");
    sll.removeAfter(sll.head());
    expect(sll.isEmpty()).to_be_truthy();
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
