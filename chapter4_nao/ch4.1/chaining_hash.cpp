#include "chaining_hash.h"

ChainingHash::ChainingHash()
{
    t = new SLinkedList[0];
}

void ChainingHash::reallocate(int mp)
{
    m = mp;
    SLinkedList *tp = new SLinkedList[mp];
    for (int i = 0; i < n; i++)
    {
        tp[i] = t[i];
    }
    delete t;
    t = tp;
}
