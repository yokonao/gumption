#include "initial_list.h"
#include <expectation.h>

void testInitialList()
{
    int n = 10;
    UArray<int> a = initial_list_random(n);
    UArray<int> b = initial_list_good(n);
    UArray<int> c = initial_list_worst(n);
    expect(a.size()).to_be(n);
    expect(b.size()).to_be(n);
    expect(c.size()).to_be(n);
}

int main()
{
    testInitialList();
}