#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP
#include <array.h>
#include <initializer_list>
#include <uarray.h>

class BinaryHeapPriorityQueue
{
private:
    int n = 0;
    int w = 0;
    Array<int> h;
    void swap(int i, int j);
    void siftUp(int i);
    void siftDownSimply(int i);
    void siftDownBinary(int i);
    void siftDown(int i);
    void heapify();

public:
    BinaryHeapPriorityQueue(int w);
    BinaryHeapPriorityQueue(int w, std::initializer_list<int> init);
    BinaryHeapPriorityQueue(int w, UArray<int> a);

    int min();
    void insert(int e);
    int deleteMin();
};
#endif
