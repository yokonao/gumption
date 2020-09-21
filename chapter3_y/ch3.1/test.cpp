#include "DLLinkedlist.h"
#include "FreeList.h"

#include <iostream>
#include <cassert>
using namespace std;
void testLinkedListDefaultConstructor()
{
    List *ll = new List();
    assert(ll->head() == ll->head()->next);
    assert(ll->head() == ll->head()->prev);
    assert(ll->head()->isDummy);
    assert(ll->isEmpty());
    delete ll;
}
void testFreeList(){
    assert(FreeList::isEmpty());
    FreeList::checkFreeList();
    assert(!FreeList::isEmpty());
    assert(FreeList::head()->next == FreeList::head()->prev);
}
int main(){
    cout << "start test" << endl;
    void testLinkedListDefaultConstructor();
    void testFreeList();
    cout << "done" << endl;

    return 0;
}

