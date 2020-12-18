#ifndef S_LIKED_LIST_HPP
#define S_LIKED_LIST_HPP

#include <string>
#include <cassert>
#include <iostream>

template<class Key, class Value>
struct SItem
{
    Key e;
    Value value;
    SItem *next;
    bool isDummy;

    SItem()
    {
        next = this;
        isDummy = true;
    }

    SItem(Key e, Value value, SItem *next)
    {
        this->e = e;
        this->value = value;
        this->next = next;
        isDummy = false;
    }
};

template<class Key, class Value>
class SLinkedList
{
    SItem<Key, Value> m_head;
    SItem<Key, Value> *m_last;
    SItem<Key, Value> *freeHead;

    void splice(SItem<Key, Value> *ap, SItem<Key, Value> *b, SItem<Key, Value> *t)
    {
        // apがvalidなLinkedListに所属しているか
        SItem<Key, Value> *tmp = ap->next;
        while (!tmp->isDummy)
        {
            assert(tmp != ap);
            tmp = tmp->next;
        }
        // 同リスト内に[a...b]が存在し、tが含まれない
        tmp = ap->next;
        while (tmp != b)
        {
            assert(!tmp->isDummy);
            assert(tmp != t);
            tmp = tmp->next;
        }

        SItem<Key, Value> *a = ap->next;
        ap->next = b->next;
        SItem<Key, Value> *tp = t->next;
        b->next = tp;
        t->next = a;
    };

    void checkFreeList()
    {
        if (freeHead->next == freeHead)
        {
            SItem<Key, Value> *next = new SItem<Key, Value>("", "", freeHead);
            freeHead->next = next;
        }
    }

public:
    SLinkedList()
    {
        freeHead = new SItem<Key, Value>();
    }

    SItem<Key, Value> *head() { return &m_head; }

    bool isEmpty() { return &m_head == m_head.next; }

    SItem<Key, Value> *first()
    {
        assert(!isEmpty());
        return m_head.next;
    }

    SItem<Key, Value> *last()
    {
        assert(!isEmpty());
        return m_last;
    }

    // For Debug
    std::string all()
    {
        if (isEmpty())
        {
            return "[]";
        }
        else
        {
            SItem<Key, Value> *tmp = first();
            std::string result;
            while (!tmp->isDummy)
            {
                result += tmp->e;
                result += ',';
                tmp = tmp->next;
            }
            return result;
        }
    }

    SItem<Key, Value> *insertAfter(Key e, Value value, SItem<Key, Value> *a)
    {
        checkFreeList();
        SItem<Key, Value> *ap = freeHead;
        splice(ap, ap->next, a);
        a->next->e = e;
        a->next->value = value;
        if (a->next->next->isDummy)
        {
            m_last = a->next;
        }
        return a->next;
    }

    void pushBack(Key e, Value value)
    {
        if (isEmpty())
        {
            insertAfter(e, value, head());
        }
        else
        {
            insertAfter(e, value, last());
        }
    }

    void removeAfter(SItem<Key, Value> *bp)
    {
        SItem<Key, Value> *b = bp->next;
        assert(!b->isDummy);
        splice(bp, b, freeHead);
        if (bp->next->isDummy)
        {
            m_last = bp;
        }
    }
};

#endif
