#include <iostream>
#include <cassert>
#include "item.h"
#include "linked_list.h"
#include "free_list.h"

int main()
{
    LinkedList ll;
    assert(ll.head() == ll.head()->next);
    assert(ll.head() == ll.head()->prev);
    assert(ll.head()->isDummy);
    assert(ll.isEmpty());

    assert(FreeList::isEmpty());
    FreeList::check();
    assert(!FreeList::isEmpty());
    assert(FreeList::head()->next == FreeList::head()->prev);
    return 0;
}
