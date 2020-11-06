#include <stack.h>
#include <expectation.h>
#include <iostream>

void testStackConstructer()
{
    Stack<int> s;
    expect(s.size()).to_be(0);
}

void testStackPushBack()
{
    Stack<int> s;
    s.pushBack(1);
    expect(s.size()).to_be(1);
    expect(s.last()).to_be(1);

    s.pushBack(3);
    expect(s.size()).to_be(2);
    expect(s.last()).to_be(3);
}

void testStackPopBack()
{
    Stack<int> s;
    s.pushBack(1);
    s.pushBack(3);
    s.pushBack(4);
    expect(s.size()).to_be(3);
    expect(s.last()).to_be(4);

    s.popBack();
    expect(s.size()).to_be(2);
    expect(s.last()).to_be(3);

    s.popBack();
    expect(s.size()).to_be(1);
    expect(s.last()).to_be(1);
}
void testStackEqual()
{
    Stack<int> s;
    Stack<int> t;
    s.pushBack(1);
    s.pushBack(3);
    s.pushBack(4);
    t = s;
    expect(t.size()).to_be(3);
    expect(t.last()).to_be(4);
}
int main()
{
    executeTestSuite("スタックの初期化テスト", testStackConstructer);
    executeTestSuite("スタックの挿入テスト", testStackPushBack);
    executeTestSuite("スタックの削除テスト", testStackPopBack);
    executeTestSuite("スタックの代入テスト", testStackEqual);

    return 0;
}