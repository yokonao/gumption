#include "DLLinkedlist.h"
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

int main(){
    void testLinkedListDefaultConstructor();
    return 0;
}

