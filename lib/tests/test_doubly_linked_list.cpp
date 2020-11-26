#include <doubly_linked_list.h>
#include <expectation.h>
#include <string>

std::string DoublyLinkedListAll(DoublyLinkedList<int> *ll)
{
    if (ll->isEmpty())
    {
        return "[]";
    }
    else
    {
        DoublyLinkedItem<int> *tmp = ll->head()->next;
        std::string result;
        while (!tmp->isDummy)
        {
            result += std::to_string(tmp->body);
            result += ',';
            tmp = tmp->next;
        }
        return result;
    }
}

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

void testDoublyLinkedListConstructor()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    assert(ll->head() == ll->head()->next);
    assert(ll->head() == ll->head()->prev);
    assert(ll->head()->isDummy);
    assert(ll->isEmpty());
    assert(ll->isEmpty());
    delete ll;
}

void testInsertAndRemove()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    assert(ll->isEmpty());
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    assert(ll->first()->body == 1);
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    assert(ll->last()->body == 2 && ll->first()->body == 1);
    ll->remove(two);
    assert(ll->first()->body == 1 && ll->last()->body == 1);
    ll->remove(one);
    assert(ll->isEmpty());
    delete ll;
}
void testMoveToFront()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    DoublyLinkedItem<int> *three = ll->insertAfter(3, two);
    DoublyLinkedItem<int> *four = ll->insertAfter(4, three);
    assert(DoublyLinkedListAll(ll) == "1,2,3,4,");
    ll->moveToFront(four);
    assert(DoublyLinkedListAll(ll) == "4,1,2,3,");
    delete ll;
}

void testMoveToBack()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    DoublyLinkedItem<int> *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(DoublyLinkedListAll(ll) == "1,2,3,4,");
    ll->moveToBack(one);
    assert(DoublyLinkedListAll(ll) == "2,3,4,1,");
    delete ll;
}

void testPopFront()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    DoublyLinkedItem<int> *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(DoublyLinkedListAll(ll) == "1,2,3,4,");
    ll->popFront();
    assert(DoublyLinkedListAll(ll) == "2,3,4,");
    delete ll;
}

void testPopBack()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    DoublyLinkedItem<int> *three = ll->insertAfter(3, two);
    ll->insertAfter(4, three);
    assert(DoublyLinkedListAll(ll) == "1,2,3,4,");
    ll->popBack();
    assert(DoublyLinkedListAll(ll) == "1,2,3,");
    delete ll;
}

void testInsertBefore()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    DoublyLinkedItem<int> *three = ll->insertAfter(3, two);
    assert(DoublyLinkedListAll(ll) == "1,2,3,");
    ll->insertBefore(100, three);
    assert(DoublyLinkedListAll(ll) == "1,2,100,3,");
    delete ll;
}

void testPushFront()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    ll->insertAfter(3, two);
    assert(DoublyLinkedListAll(ll) == "1,2,3,");
    ll->pushFront(100);
    assert(DoublyLinkedListAll(ll) == "100,1,2,3,");
    delete ll;
}

void testPushBack()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    ll->pushBack(1);
    ll->pushBack(2);
    ll->pushBack(3);
    assert(DoublyLinkedListAll(ll) == "1,2,3,");
    ll->pushBack(100);
    assert(DoublyLinkedListAll(ll) == "1,2,3,100,");
    delete ll;
}

void testMakeEmpty()
{
    DoublyLinkedList<int> *ll = new DoublyLinkedList<int>();
    DoublyLinkedItem<int> *one = ll->insertAfter(1, ll->head());
    DoublyLinkedItem<int> *two = ll->insertAfter(2, one);
    ll->insertAfter(3, two);
    assert(DoublyLinkedListAll(ll) == "1,2,3,");
    ll->makeEmpty();
    assert(DoublyLinkedListAll(ll) == "[]");
    delete ll;
}

void testPrint()
{
    DoublyLinkedList<int> ll;
    DoublyLinkedItem<int> *one = ll.insertAfter(1, ll.head());
    ll.insertAfter(2, one);
    std::cout << ll << std::endl;
}

int main()
{
    executeTestSuite("アイテムのテスト", testItem);
    executeTestSuite("双方向連結リストのコンストラクタのテスト", testDoublyLinkedListConstructor);
    executeTestSuite("InsertとRemoveのテスト", testInsertAndRemove);
    executeTestSuite("MoveToFrontのテスト", testMoveToFront);
    executeTestSuite("MoveToBackのテスト", testMoveToBack);
    executeTestSuite("PopFrontのテスト", testPopFront);
    executeTestSuite("PopBackのテスト", testPopBack);
    executeTestSuite("InsertBeforeのテスト", testInsertBefore);
    executeTestSuite("PushFrontのテスト", testPushFront);
    executeTestSuite("PushBackのテスト", testPushBack);
    executeTestSuite("MakeEmptyのテスト", testMakeEmpty);
    executeTestSuite("プリントのテスト", testPrint);
    return 0;
}
