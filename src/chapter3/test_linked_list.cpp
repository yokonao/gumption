#include <cassert>
#include <iostream>
#include <string>
#include "item.h"
#include "linked_list.h"
#include "free_list.h"

void testLinkedListDefaultConstructor()
{
    LinkedList *ll = new LinkedList();
    assert(ll->head() == ll->head()->next);
    assert(ll->head() == ll->head()->prev);
    assert(ll->head()->isDummy);
    assert(ll->isEmpty());
    delete ll;
}

void testFreeList()
{
    assert(FreeList::isEmpty());
    FreeList::check();
    assert(!FreeList::isEmpty());
    assert(FreeList::head()->next == FreeList::head()->prev);
    FreeList::clear();
    assert(FreeList::isEmpty());
}

void testInsertAndRemove()
{
    LinkedList *ll = new LinkedList();
    assert(ll->isEmpty());
    Item *one = ll->insertAfter(1, ll->head());
    assert(ll->first()->e == 1);
    Item *two = ll->insertAfter(2, one);
    assert(ll->last()->e == 2 && ll->first()->e == 1);
    ll->remove(two);
    assert(ll->first()->e == 1 && ll->last()->e == 1);
    ll->remove(one);
    assert(ll->isEmpty());
    delete ll;
}

void testMoveToFront()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    Item *three = ll->insertAfter(3, two);
    Item *four = ll->insertAfter(4, three);
    assert(ll->all() == "1,2,3,4,");
    ll->moveToFront(four);
    assert(ll->all() == "4,1,2,3,");
    delete ll;
}

void testMoveToBack()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    Item *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(ll->all() == "1,2,3,4,");
    ll->moveToBack(one);
    assert(ll->all() == "2,3,4,1,");
    delete ll;
}

void testPopFront()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    Item *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(ll->all() == "1,2,3,4,");
    ll->popFront();
    assert(ll->all() == "2,3,4,");
    delete ll;
}

void testPopBack()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    Item *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(ll->all() == "1,2,3,4,");
    ll->popBack();
    assert(ll->all() == "1,2,3,");
    delete ll;
}

void testInsertBefore()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    ll->insertAfter(3, two);
    assert(ll->all() == "1,2,3,");
    ll->insertBefore(100, two);
    assert(ll->all() == "1,100,2,3,");
    delete ll;
}

void testPushFront()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    ll->insertAfter(3, two);
    assert(ll->all() == "1,2,3,");
    ll->pushFront(100);
    assert(ll->all() == "100,1,2,3,");
    delete ll;
}

void testPushBack()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    ll->insertAfter(3, two);
    assert(ll->all() == "1,2,3,");
    ll->pushBack(100);
    assert(ll->all() == "1,2,3,100,");
    delete ll;
}

void testMakeEmpty()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    ll->insertAfter(3, two);
    assert(ll->all() == "1,2,3,");
    ll->makeEmpty();
    assert(ll->all() == "[]");
    delete ll;
}

void testFindNext()
{
    LinkedList *ll = new LinkedList();
    Item *one = ll->insertAfter(1, ll->head());
    Item *two = ll->insertAfter(2, one);
    Item *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(ll->all() == "1,2,3,4,");
    assert(ll->findNext(100, ll->first())->isDummy);
    assert(ll->findNext(3, ll->first()) == three);
}

int main()
{
    std::cout << "TEST START" << std::endl;
    testLinkedListDefaultConstructor();
    testFreeList();
    testInsertAndRemove();
    testMoveToFront();
    testMoveToBack();
    testPopFront();
    testPopBack();
    testInsertBefore();
    testPushFront();
    testPushFront();
    testMakeEmpty();
    testFindNext();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
