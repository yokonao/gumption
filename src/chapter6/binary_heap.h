#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP
#include <uarray.h>
class BinaryHeapPriorityQueue
{
private:
    int n = 0;
    UArray<int> h;
    int at(int i);
    void swap(int i, int j);
    void siftUp(int i);

public:
    int min();
    void insert(int e);
};
#endif