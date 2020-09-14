#include "procedure.h"
#include <cassert>

void splice(Item *a, Item *b, Item *t)
{
    Item *tmp = a;
    while (tmp != b)
    {
        assert(!tmp->isDummy);
        assert(tmp != t);
        assert(tmp != a);
    }

    Item *ap = a->prev;
    Item *bp = b->next;
    ap->next = bp;
    bp->prev = ap;

    Item *tp = t->next;
    b->next = tp;
    a->prev = t;
    t->next = a;
    tp->prev = b;
};
