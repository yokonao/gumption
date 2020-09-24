#include <iostream>
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
    SItem *ruby = sll.insertAfter("Ruby", "", sll.head());
    expect(sll.all()).to_be("Ruby,");
    expect(ruby).to_be(sll.head()->next);
    expect(ruby->next).to_be(sll.head());
    SItem *python = sll.insertAfter("Python", "", ruby);
    expect(sll.all()).to_be("Ruby,Python,");
    SItem *php = sll.insertAfter("PHP", "", sll.head());
    expect(sll.all()).to_be("PHP,Ruby,Python,");
}

void testPushBack()
{
    SLinkedList sll;
    expect(sll.isEmpty()).to_be_truthy();
    sll.pushBack("Java", "");
    expect(sll.all()).to_be("Java,");
    sll.pushBack("C++", "");
    expect(sll.all()).to_be("Java,C++,");
    sll.pushBack("C#", "");
    expect(sll.all()).to_be("Java,C++,C#,");
}

void testRemoveAfter()
{
    SLinkedList sll;
    expect(sll.isEmpty()).to_be_truthy();
    SItem *dart = sll.insertAfter("Dart", "", sll.head());
    expect(sll.all()).to_be("Dart,");
    expect(dart).to_be(sll.head()->next);
    expect(dart->next).to_be(sll.head());
    SItem *swift = sll.insertAfter("Swift", "", dart);
    expect(sll.all()).to_be("Dart,Swift,");
    SItem *kotlin = sll.insertAfter("Kotlin", "", sll.head());
    expect(sll.all()).to_be("Kotlin,Dart,Swift,");
    sll.removeAfter(sll.head());
    expect(sll.all()).to_be("Dart,Swift,");
    sll.removeAfter(dart);
    expect(sll.all()).to_be("Dart,");
    sll.removeAfter(sll.head());
    expect(sll.isEmpty()).to_be_truthy();
}

void testHash()
{
    expect(hashPrime("a")).to_be(1);
    expect(hashPrime("b")).to_be(2);
    expect(hashPrime("z")).to_be(26);
    expect(hashPrime("az")).to_be(52);
    expect(hashPrime("ruby")).to_be(330641);
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("");
    });
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("Ruby");
    });
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("ruビー");
    });
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("るびー");
    });
    expect_error<std::length_error>([] {
        unsigned long long N = hashPrime("rubyonrails");
    });
    expect(hash("ruby", 1000)).to_be(641);
    expect(hash("zzzzzz", 10)).to_be(6);
}

void testChainingHash()
{
    ChainingHash ch;
    expect(ch.find("ruby")).to_be("");

    ch.insert("ruby", "rails");
    ch.insert("python", "django");
    ch.insert("dart", "flutter");

    expect(ch.find("ruby")).to_be("ruby");
    expect(ch["ruby"]).to_be("rails");
    expect(ch.find("python")).to_be("python");
    expect(ch["python"]).to_be("django");
    expect(ch.find("dart")).to_be("dart");
    expect(ch["dart"]).to_be("flutter");
    expect(ch.find("java")).to_be("");
    expect(ch["java"]).to_be("");

    ch.remove("python");
    expect(ch.find("python")).to_be("");
    ch.remove("ruby");
    expect(ch.find("ruby")).to_be("");
    ch.remove("dart");
    expect(ch.find("dart")).to_be("");
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
    testHash();
    testChainingHash();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
