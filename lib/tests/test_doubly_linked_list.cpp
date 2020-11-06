#include <doubly_linked_list.h>
#include <expectation.h>

void testItem()
{
    DoublyLinkedItem<int> dummy;
    expect(dummy.isDummy).to_be_truthy();
    expect(dummy.body).to_be(0);
    DoublyLinkedItem<int> one(10, &dummy, &dummy);
    expect(one.body).to_be(10);
    expect(one.next).to_be(&dummy);
    expect(one.prev).to_be(&dummy);
    expect(one.isDummy).to_be_falsy();
}

int main()
{
    executeTestSuite("アイテムのテスト", testItem);
    return 0;
}
