#include <expectation.h>
#include "binary_heap.h"

void testBinaryHeapSimple()
{
    BinaryHeapPriorityQueue q(3);
    q.insert(5);
    q.insert(4);
    q.insert(3);
    expect(q.min()).to_be(3);
}
void testBinaryHeap()
{
    BinaryHeapPriorityQueue q(10);
    q.insert(5);
    q.insert(4);
    q.insert(3);
    q.insert(8);
    q.insert(7);
    q.insert(19);
    q.insert(5);
    q.insert(40);
    q.insert(79);

    expect(q.min()).to_be(3);
}

int main()
{
    executeTestSuite("ヒープのテストSimple", testBinaryHeapSimple);
    executeTestSuite("ヒープのテスト", testBinaryHeap);
    return 0;
}
