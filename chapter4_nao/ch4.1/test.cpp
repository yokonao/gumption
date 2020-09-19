#include <iostream>
#include <cassert>
#include "s_item.h"

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

int main()
{
    std::cout << "TEST START" << std::endl;
    testSItem();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
