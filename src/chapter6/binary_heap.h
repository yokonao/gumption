#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP
#include <array.h>
class BinaryHeapPriorityQueue
{
private:
    int n = 0;
    int w = 0;
    Array<int> h;
    int at(int i);
    void swap(int i, int j);
    void siftUp(int i);
    void siftDown(int i);

public:
    BinaryHeapPriorityQueue(int w);
    int min();
    void insert(int e);
    int deleteMin();
};
#endif
