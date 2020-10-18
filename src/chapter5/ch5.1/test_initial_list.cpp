#include "initial_list.h"
#include <expectation.h>
int max_uarray(const UArray<int> &a)
{
    if (a.size() == 0)
    {
        return 0;
    }
    int max_value = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > max_value)
        {
            max_value = a[i];
        }
    }
    return max_value;
}
int min_uarray(const UArray<int> &a)
{
    if (a.size() == 0)
    {
        return 0;
    }
    int min_value = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < min_value)
        {
            min_value = a[i];
        }
    }
    return min_value;
}
void testInitialList()
{
    int n = 10;
    UArray<int> a = initial_list_random(n);
    UArray<int> b = initial_list_good(n);
    UArray<int> c = initial_list_worst(n);
    expect(a.size()).to_be(n);
    expect(b.size()).to_be(n);
    expect(c.size()).to_be(n);
    expect(max_uarray(a) <= n).to_be_truthy();
    expect(min_uarray(a) > 0).to_be_truthy();
}

int main()
{
    testInitialList();
}