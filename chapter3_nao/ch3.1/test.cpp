#include <cassert>
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

int main()
{
    testLinkedListDefaultConstructor();
    testFreeList();
    testInsertAndRemove();
    return 0;
}
