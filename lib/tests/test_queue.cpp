#include <queue.h>
#include <expectation.h>
#include <iostream>

void testQueueConstructer()
{
    Queue<int> q;
    expect(q.size()).to_be(0);
    expect(q.isEmpty()).to_be_truthy();
}

void testQueuePushBack()
{
    Queue<int> q;
    q.pushBack(1);
    expect(q.size()).to_be(1);
    q.pushBack(3);
    expect(q.size()).to_be(2);
}

void testQueuePopFront()
{
    Queue<int> q;
    q.pushBack(1);
    q.pushBack(3);
    q.pushBack(4);
    expect(q.size()).to_be(3);
    expect(q.popFront()).to_be(1);
    expect(q.popFront()).to_be(3);
    expect(q.popFront()).to_be(4);
}

int main()
{
    executeTestSuite("キューの初期化テスト", testQueueConstructer);
    executeTestSuite("キューの挿入テスト", testQueuePushBack);
    executeTestSuite("キューの削除テスト", testQueuePopFront);

    return 0;
}