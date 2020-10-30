#include <expectation.h>
#include <binary_heap.h>

void testBinaryHeapSimple()
{
    BinaryHeapPriorityQueue q(3);
    q.insert(5);
    q.insert(4);
    q.insert(3);
    expect(q.min()).to_be(3);
}

void testBinaryHeapBinary()
{
    BinaryHeapPriorityQueue q(3, 1);
    q.insert(5);
    q.insert(4);
    q.insert(3);
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
    expect(pq.deleteMin()).to_be(1);
    expect(pq.min()).to_be(5);
    expect(pq.deleteMin()).to_be(5);
    expect(pq.min()).to_be(12);
    expect(pq.deleteMin()).to_be(12);
    expect(pq.min()).to_be(23);
    expect(pq.deleteMin()).to_be(23);
    expect(pq.min()).to_be(28);
    expect(pq.deleteMin()).to_be(28);
    expect(pq.min()).to_be(35);
    expect(pq.deleteMin()).to_be(35);
    expect(pq.min()).to_be(67);
    expect(pq.deleteMin()).to_be(67);
    expect(pq.min()).to_be(77);
    expect(pq.deleteMin()).to_be(77);
    expect(pq.min()).to_be(99);
    expect(pq.deleteMin()).to_be(99);
    expect(pq.min()).to_be(100);
    expect(pq.deleteMin()).to_be(100);
}

void testFromInitializerListSimple()
{
    BinaryHeapPriorityQueue pq(10, {100, 23, 35, 67, 28, 12, 1, 5, 99, 77});

    expect(pq.min()).to_be(1);
    expect(pq.deleteMin()).to_be(1);
    expect(pq.min()).to_be(5);
    expect(pq.deleteMin()).to_be(5);
    expect(pq.min()).to_be(12);
    expect(pq.deleteMin()).to_be(12);
    expect(pq.min()).to_be(23);
    expect(pq.deleteMin()).to_be(23);
    expect(pq.min()).to_be(28);
    expect(pq.deleteMin()).to_be(28);
    expect(pq.min()).to_be(35);
    expect(pq.deleteMin()).to_be(35);
    expect(pq.min()).to_be(67);
    expect(pq.deleteMin()).to_be(67);
    expect(pq.min()).to_be(77);
    expect(pq.deleteMin()).to_be(77);
    expect(pq.min()).to_be(99);
    expect(pq.deleteMin()).to_be(99);
    expect(pq.min()).to_be(100);
    expect(pq.deleteMin()).to_be(100);
}
void testFromInitializerListBinary()
{
    BinaryHeapPriorityQueue pq(10, {100, 23, 35, 67, 28, 12, 1, 5, 99, 77}, 1);

    expect(pq.min()).to_be(1);
    expect(pq.deleteMin()).to_be(1);
    expect(pq.min()).to_be(5);
    expect(pq.deleteMin()).to_be(5);
    expect(pq.min()).to_be(12);
    expect(pq.deleteMin()).to_be(12);
    expect(pq.min()).to_be(23);
    expect(pq.deleteMin()).to_be(23);
    expect(pq.min()).to_be(28);
    expect(pq.deleteMin()).to_be(28);
    expect(pq.min()).to_be(35);
    expect(pq.deleteMin()).to_be(35);
    expect(pq.min()).to_be(67);
    expect(pq.deleteMin()).to_be(67);
    expect(pq.min()).to_be(77);
    expect(pq.deleteMin()).to_be(77);
    expect(pq.min()).to_be(99);
    expect(pq.deleteMin()).to_be(99);
    expect(pq.min()).to_be(100);
    expect(pq.deleteMin()).to_be(100);
}
void testFromUArraySimple()
{
    UArray<int> a{100, 23, 35, 67, 28, 12, 1, 5, 99, 77};
    BinaryHeapPriorityQueue pq(10, a);

    expect(pq.min()).to_be(1);
    expect(pq.deleteMin()).to_be(1);
    expect(pq.min()).to_be(5);
    expect(pq.deleteMin()).to_be(5);
    expect(pq.min()).to_be(12);
    expect(pq.deleteMin()).to_be(12);
    expect(pq.min()).to_be(23);
    expect(pq.deleteMin()).to_be(23);
    expect(pq.min()).to_be(28);
    expect(pq.deleteMin()).to_be(28);
    expect(pq.min()).to_be(35);
    expect(pq.deleteMin()).to_be(35);
    expect(pq.min()).to_be(67);
    expect(pq.deleteMin()).to_be(67);
    expect(pq.min()).to_be(77);
    expect(pq.deleteMin()).to_be(77);
    expect(pq.min()).to_be(99);
    expect(pq.deleteMin()).to_be(99);
    expect(pq.min()).to_be(100);
    expect(pq.deleteMin()).to_be(100);
}

void testFromUArrayBinary()
{
    UArray<int> a{100, 23, 35, 67, 28, 12, 1, 5, 99, 77};
    BinaryHeapPriorityQueue pq(10, a, 1);

    expect(pq.min()).to_be(1);
    expect(pq.deleteMin()).to_be(1);
    expect(pq.min()).to_be(5);
    expect(pq.deleteMin()).to_be(5);
    expect(pq.min()).to_be(12);
    expect(pq.deleteMin()).to_be(12);
    expect(pq.min()).to_be(23);
    expect(pq.deleteMin()).to_be(23);
    expect(pq.min()).to_be(28);
    expect(pq.deleteMin()).to_be(28);
    expect(pq.min()).to_be(35);
    expect(pq.deleteMin()).to_be(35);
    expect(pq.min()).to_be(67);
    expect(pq.deleteMin()).to_be(67);
    expect(pq.min()).to_be(77);
    expect(pq.deleteMin()).to_be(77);
    expect(pq.min()).to_be(99);
    expect(pq.deleteMin()).to_be(99);
    expect(pq.min()).to_be(100);
    expect(pq.deleteMin()).to_be(100);
}

int main()
{
    executeTestSuite("ヒープのテストSimple", testBinaryHeapSimple);
    executeTestSuite("ヒープのテストBinary", testBinaryHeapBinary);
    executeTestSuite("最小値削除テスト", testDeleteMin);

    executeTestSuite("初期化リストを使ったコンストラクタのテストSimple", testFromInitializerListSimple);
    executeTestSuite("初期化リストを使ったコンストラクタのテストBinary", testFromInitializerListBinary);

    executeTestSuite("UArrayを使ったコンストラクタのテストSimple", testFromUArraySimple);
    executeTestSuite("UArrayを使ったコンストラクタのテストBinary", testFromUArrayBinary);

    return 0;
}
