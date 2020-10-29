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
    siftUp((i - 1) / 2);
}

void BinaryHeapPriorityQueue::siftDownSimply(int i)
{
    if ((i + 1) * 2 <= n)
    {
        int m = 0;

        if ((i + 1) * 2 + 1 > n)
        {
            m = i * 2 + 1;
        }
        else if (h[i * 2 + 1] <= h[(i + 1) * 2])
        {
            m = i * 2 + 1;
        }
        else
        {
            m = (i + 1) * 2;
        }

        if (h[i] > h[m])
        {
            swap(i, m);
            siftDown(m);
        }
    }
}

void BinaryHeapPriorityQueue::siftDownBinary(int i)
{
}

void BinaryHeapPriorityQueue::siftDown(int i)
{
    siftDownSimply(i);
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

int BinaryHeapPriorityQueue::deleteMin()
{
    assert(n > 0);
    int result = h[0];
    h[0] = h[n - 1];
    n--;
    siftDown(0);
    return result;
}
