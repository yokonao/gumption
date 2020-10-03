#ifndef S_LIKED_LIST_HPP
#define S_LIKED_LIST_HPP

#include <string>
#include <cassert>

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

class SLinkedList
{
    SItem m_head;
    SItem *m_last;

public:
    SLinkedList()
    {
        SItem m_head;
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

    SItem *insertAfter(std::string e, std::string value, SItem *a);

    void pushBack(std::string e, std::string value);

    void removeAfter(SItem *bp);
};

class SFreeList
{
private:
    static SLinkedList m_SLinkedList;

public:
    static SItem *head() { return m_SLinkedList.head(); }

    static bool isEmpty() { return m_SLinkedList.isEmpty(); }

    static SItem *first() { return m_SLinkedList.first(); }

    static SItem *last() { return m_SLinkedList.last(); }

    static void check()
    {
        // 空ならば要素を追加する
        if (m_SLinkedList.isEmpty())
        {
            SItem *h = m_SLinkedList.head();
            SItem *a = new SItem("", "", h);
            h->next = a;
        }
    }

    static void clear()
    {
        SItem *head = m_SLinkedList.head();
        SItem *tmp = head->next;
        while (!tmp->isDummy)
        {
            SItem *next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head->next = head;
    }
};

SItem *SLinkedList::insertAfter(std::string e, std::string value, SItem *a)
{
    SFreeList::check();
    SItem *ap = SFreeList::head();
    splice(ap, ap->next, a);
    a->next->e = e;
    a->next->value = value;
    if (a->next->next->isDummy)
    {
        m_last = a->next;
    }
    return a->next;
}

void SLinkedList::pushBack(std::string e, std::string value)
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

void SLinkedList::removeAfter(SItem *bp)
{
    SItem *b = bp->next;
    assert(!b->isDummy);
    splice(bp, b, SFreeList::head());
    if (bp->next->isDummy)
    {
        m_last = bp;
    }
}

#endif
