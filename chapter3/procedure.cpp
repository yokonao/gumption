#include "procedure.h"
#include <cassert>

void splice(Item<int> *a, Item<int> *b, Item<int> *t)
{
    Item<int> *tmp = a;
    while (tmp != b)
    {
        assert(!tmp->isDummy);
        assert(tmp != t);
        assert(tmp != a);
    }

    Item<int> *ap = a->prev;
    Item<int> *bp = b->next;
    ap->next = bp;
    bp->prev = ap;

    Item<int> *tp = t->next;
    b->next = tp;
    a->prev = t;
    t->next = a;
    tp->prev = b;
};
