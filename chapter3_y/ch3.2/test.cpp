#include <iostream>
#include <cassert>
#include "uarray.h"

void test()
{
    UArray ua(4, 2);
    assert(ua.size() == 0);
    ua.pushBack(1);
    assert(ua[0] == 1);
    ua.pushBack(10);
    assert(ua[0] == 1 && ua[1] == 10);
    ua.pushBack(100);
    assert(ua[0] == 1 && ua[1] == 10 && ua[2] == 100);
    assert(ua.size() == 3);
    ua.popBack();
    assert(ua[0] == 1 && ua[1] == 10);
    ua.popBack();
    assert(ua[0] == 1);
    ua.popBack();
    assert(ua.size() == 0);
}

int main()
{
    std::cout << "TEST START" << std::endl;
    test();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}