#include <array>
#include <cassert>
#include "u_array.h"

UArray::UArray()
{
    b = new int[0];
}

int UArray::operator[](int i)
{
    assert(i >= 0 && i < n);
    return b[i];
}

int UArray::size() { return n; }

void UArray::pushBack(int e)
{
    if (n == w)
    {
        reallocate(beta * n);
    }
    b[n] = e;
    n++;
}

void UArray::popBack()
{
    assert(n > 0);
    n--;
    if (w >= alpha * n && n > 0)
    {
        reallocate(beta * n);
    }
}

void UArray::reallocate(int wp)
{
    w = wp;
    int *bp = new int[wp];
    for (int i = 0; i < n; i++)
    {
        bp[i] = b[i];
    }
    delete b;
    b = bp;
}
