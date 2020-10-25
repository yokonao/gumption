#include "binary_heap.h"
#include <cassert>

void BinaryHeapPriorityQueue::swap(int i, int j)
{
    int buff = h[i];
    h[i] = h[j];
    h[j] = buff;
}

void BinaryHeapPriorityQueue::siftUp(int i)
{
    if (i == 0 or h[(i - 1) / 2] <= h[i])
        return;
    swap(i, (i - 1) / 2);
    siftUp(i / 2);
}

int BinaryHeapPriorityQueue::min()
{
    assert(n > 0);
    return h[0];
}

void BinaryHeapPriorityQueue::insert(int e)
{
    h.pushBack(e);
    n++;
    siftUp(n - 1);
}
