#ifndef DOUBLY_LIKED_LIST_HPP
#define DOUBLY_LIKED_LIST_HPP

#include <cassert>

template <typename T>
class DoublyLinkedItem
{
public:
    T body;
    DoublyLinkedItem *prev;
    DoublyLinkedItem *next;
    bool isDummy;

    DoublyLinkedItem()
    {
        body = T();
        prev = this;
        next = this;
        isDummy = true;
    }

    DoublyLinkedItem(T body, DoublyLinkedItem *prev, DoublyLinkedItem *next)
    {
        this->body = body;
        this->prev = prev;
        this->next = next;
        isDummy = false;
    }
};

template <typename T>
class DoublyLinkedList
{
private:
    DoublyLinkedItem<T> _head;

    void splice(DoublyLinkedItem<T> *a, DoublyLinkedItem<T> *b, DoublyLinkedItem<T> *t)
    {
        // aがvalidなLinkedListに所属しているか
        DoublyLinkedItem<T> *tmp = a->next;
        while (!tmp->isDummy)
        {
            assert(tmp != a);
            tmp = tmp->next;
        }
        // 同リスト内に[a...b]が存在し、tが含まれない
        tmp = a;
        while (tmp != b)
        {
            assert(!tmp->isDummy);
            assert(tmp != t);
            tmp = tmp->next;
        }

        DoublyLinkedItem<T> *ap = a->prev;
        DoublyLinkedItem<T> *bp = b->next;
        ap->next = bp;
        bp->prev = ap;

        DoublyLinkedItem<T> *tp = t->next;
        b->next = tp;
        a->prev = t;
        t->next = a;
        tp->prev = b;
    };

public:
    DoublyLinkedList()
    {
    }

    ~DoublyLinkedList()
    {
    }

    DoublyLinkedItem<T> *head()
    {
        return &_head;
    }

    bool isEmpty()
    {
        return &_head == _head.next;
    }

    DoublyLinkedItem<T> *first()
    {
        assert(!isEmpty());
        return _head.next;
    }

    DoublyLinkedItem<T> *last()
    {
        assert(!isEmpty());
        return _head.prev;
    }
};

#endif
