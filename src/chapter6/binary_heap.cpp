#include "binary_heap.h"
#include <cassert>

BinaryHeapPriorityQueue::BinaryHeapPriorityQueue(int w)
{
    this->w = w;
    this->h = Array<int>(w);
}
BinaryHeapPriorityQueue::BinaryHeapPriorityQueue(int w, std::initializer_list<int> init)
{
    assert(w >= init.size());
    this->w = w;
    this->h = Array<int>(w);
    this->n = init.size();
    int idx = 0;
    for (int e : init)
    {
        h[idx] = e;
        idx++;
    }
    heapify();
}
BinaryHeapPriorityQueue::BinaryHeapPriorityQueue(int w, UArray<int> a)
{
    assert(w >= a.size());
    this->w = w;
    this->h = Array<int>(w);
    this->n = a.size();
    for (int i = 0; i < a.size(); i++)
    {
        h[i] = a[i];
    }
    heapify();
}

void BinaryHeapPriorityQueue::heapify()
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        siftDown(i);
    }
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
            siftDownSimply(m);
        }
    }
}

void BinaryHeapPriorityQueue::siftDownBinary(int i)
{
    //todo:i = 0以外のときにswap(0,p[idx])を修正
    if (n <= 1)
    {
        return;
    }
    int e = h[i];
    UArray<int> p;
    while ((i + 1) * 2 <= n)
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
        p.pushBack(m);
        i = m;
    }
    if (e <= h[p[0]])
    {
        return;
    }
    int l = 0;
    int r = p.size();
    while (l != r)
    {
        int mid = (l + r) / 2;
        if (h[p[mid]] > e)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    //swap
    for (int idx = 0; idx < l; idx++)
    {
        if (idx == 0)
        {
            swap(0, p[idx]);
        }
        else
        {
            swap(p[idx - 1], p[idx]);
        }
    }
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
