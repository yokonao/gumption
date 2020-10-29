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

void testDeleteMin()
{
    BinaryHeapPriorityQueue pq(10);
    pq.insert(100);
    pq.insert(23);
    pq.insert(35);
    pq.insert(67);
    pq.insert(28);
    pq.insert(12);
    pq.insert(1);
    pq.insert(5);
    pq.insert(99);
    pq.insert(77);

    expect(pq.min()).to_be(1);
    // expect(pq.deleteMin()).to_be(1);
    // expect(pq.min()).to_be(5);
    // expect(pq.deleteMin()).to_be(5);
    // expect(pq.min()).to_be(12);
    // expect(pq.deleteMin()).to_be(12);
    // expect(pq.min()).to_be(23);
    // expect(pq.deleteMin()).to_be(23);
    // expect(pq.min()).to_be(28);
    // expect(pq.deleteMin()).to_be(28);
    // expect(pq.min()).to_be(35);
    // expect(pq.deleteMin()).to_be(35);
    // expect(pq.min()).to_be(67);
    // expect(pq.deleteMin()).to_be(67);
    // expect(pq.min()).to_be(77);
    // expect(pq.deleteMin()).to_be(77);
    // expect(pq.min()).to_be(99);
    // expect(pq.deleteMin()).to_be(99);
    // expect(pq.min()).to_be(100);
    // expect(pq.deleteMin()).to_be(100);
}

int main()
{
    executeTestSuite("ヒープのテストSimple", testBinaryHeapSimple);
    executeTestSuite("ヒープのテスト", testBinaryHeap);
    executeTestSuite("最小値削除テスト", testDeleteMin);
    return 0;
}
