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

    std::cout << FreeList::isEmpty() << std::endl;
    std::cout << FreeList::head() << std::endl;
    return 0;
}
