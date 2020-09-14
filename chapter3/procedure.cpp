#include "procedure.h"
#include <cassert>

void splice(Item *a, Item *b, Item *t)
{
    // aがvalidなLinkedListに所属しているか
    Item *tmp = a->next;
    while(!tmp->isDummy){
        assert(tmp != a);
        tmp = tmp->next;
    }
    // 同リスト内に[a...b]が存在し、tが含まれない
    Item *tmp = a;
    while (tmp != b)
    {
        assert(!tmp->isDummy);
        assert(tmp != t);
        tmp = tmp->next;
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
