#ifndef S_LIKED_LIST_HPP
#define S_LIKED_LIST_HPP

#include <string>
#include <cassert>
#include <iostream>

struct SItem
{
    std::string e;
    std::string value;
    SItem *next;
    bool isDummy;

    SItem()
    {
        next = this;
        isDummy = true;
    }

    SItem(std::string e, std::string value, SItem *next)
    {
        this->e = e;
        this->value = value;
        this->next = next;
        isDummy = false;
    }
};

class SLinkedList
{
    SItem m_head;
    SItem *m_last;
    SItem *freeHead;

    void splice(SItem *ap, SItem *b, SItem *t)
    {
        // apがvalidなLinkedListに所属しているか
        SItem *tmp = ap->next;
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

        SItem *a = ap->next;
        ap->next = b->next;
        SItem *tp = t->next;
        b->next = tp;
        t->next = a;
    };

    void checkFreeList()
    {
        if (freeHead->next == freeHead)
        {
            SItem *next = new SItem("", "", freeHead);
            freeHead->next = next;
        }
    }

public:
    SLinkedList()
    {
        freeHead = new SItem();
    }

    SItem *head() { return &m_head; }

    bool isEmpty() { return &m_head == m_head.next; }

    SItem *first()
    {
        assert(!isEmpty());
        return m_head.next;
    }

    SItem *last()
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
            SItem *tmp = first();
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

    SItem *insertAfter(std::string e, std::string value, SItem *a)
    {
        checkFreeList();
        SItem *ap = freeHead;
        splice(ap, ap->next, a);
        a->next->e = e;
        a->next->value = value;
        if (a->next->next->isDummy)
        {
            m_last = a->next;
        }
        return a->next;
    }

    void pushBack(std::string e, std::string value)
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

    void removeAfter(SItem *bp)
    {
        SItem *b = bp->next;
        assert(!b->isDummy);
        splice(bp, b, freeHead);
        if (bp->next->isDummy)
        {
            m_last = bp;
        }
    }
};

#endif
