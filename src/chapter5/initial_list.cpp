#include <uarray.h>
#include "gen_random.h"

UArray<int> initial_list_random(int n)
{
    UArray<int> a;
    for (int i = 0; i < n; i++)
    {
        a.pushBack(gen_mt(n) + 1);
    }
    return a;
}
UArray<int> initial_list_good(int n)
{
    UArray<int> a;
    for (int i = 0; i < n; i++)
    {
        a.pushBack(i + 1);
    }
    return a;
}
UArray<int> initial_list_worst(int n)
{
    UArray<int> a;
    for (int i = 0; i < n; i++)
    {
        a.pushBack(n - i);
    }
    return a;
}