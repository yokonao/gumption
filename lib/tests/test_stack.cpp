#include <stack.h>
#include <expectation.h>
#include <iostream>

void testStackConstructer()
{
    Stack<int> s;
    expect(s.size()).to_be(0);
    expect(s.isEmpty()).to_be_truthy();
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
void testStackFind()
{
    Stack<int> s;
    s.pushBack(1);
    s.pushBack(3);
    s.pushBack(5);
    s.pushBack(7);
    expect(s.find(1)).to_be_truthy();
    expect(s.find(3)).to_be_truthy();
    expect(s.find(4)).to_be_falsy();
}
int main()
{
    executeTestSuite("スタックの初期化テスト", testStackConstructer);
    executeTestSuite("スタックの挿入テスト", testStackPushBack);
    executeTestSuite("スタックの削除テスト", testStackPopBack);
    executeTestSuite("スタックの代入テスト", testStackEqual);
    executeTestSuite("スタックの検索テスト", testStackFind);

    return 0;
}