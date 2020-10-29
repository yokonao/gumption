#include "binary_heap.h"
#include <cassert>

BinaryHeapPriorityQueue::BinaryHeapPriorityQueue(int w)
{
    this->w = w;
    this->h = Array<int>(w);
}

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
    assert(n < w);
    n++;
    h[n - 1] = e;
    siftUp(n - 1);
}
