#ifndef DOUBLY_LIKED_LIST_HPP
#define DOUBLY_LIKED_LIST_HPP

#include <cassert>
#include <ostream>
#include <iostream>
#include <functional>

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

    DoublyLinkedItem(DoublyLinkedItem *prev, DoublyLinkedItem *next)
    {
        this->prev = prev;
        this->next = next;
        isDummy = false;
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
    DoublyLinkedItem<T> *_freeHead;

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

    void checkFreeList()
    {
        if (_freeHead->next == _freeHead)
        {
            DoublyLinkedItem<T> *next = new DoublyLinkedItem<T>(_freeHead, _freeHead);
            _freeHead->next = next;
            _freeHead->prev = next;
        }
    }

public:
    DoublyLinkedList()
    {
        _freeHead = new DoublyLinkedItem<T>();
    }

    ~DoublyLinkedList()
    {
        delete _freeHead;
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

    void moveAfter(DoublyLinkedItem<T> *b, DoublyLinkedItem<T> *ap)
    {
        splice(b, b, ap);
    }

    void remove(DoublyLinkedItem<T> *b)
    {
        moveAfter(b, _freeHead);
    }

    DoublyLinkedItem<T> *insertAfter(T body, DoublyLinkedItem<T> *a)
    {
        checkFreeList();
        DoublyLinkedItem<T> *ap = _freeHead->next;
        moveAfter(ap, a);
        ap->body = body;
        return ap;
    }

    void moveToFront(DoublyLinkedItem<T> *b)
    {
        moveAfter(b, &_head);
    }

    void moveToBack(DoublyLinkedItem<T> *b)
    {
        moveAfter(b, last());
    }

    void popFront()
    {
        remove(first());
    };

    void popBack()
    {
        remove(last());
    }

    DoublyLinkedItem<T> *insertBefore(T body, DoublyLinkedItem<T> *b)
    {
        return insertAfter(body, b->prev);
    }

    void pushFront(T body)
    {
        insertAfter(body, head());
    }

    void pushBack(T body)
    {
        if (isEmpty())
        {
            insertAfter(body, head());
        }
        else
        {
            insertAfter(body, last());
        }
    }

    void makeEmpty()
    {
        splice(first(), last(), _freeHead);
    };

    void foreach (std::function<void(T)> callback)
    {
        if (isEmpty())
            return;
        DoublyLinkedItem<T> *tmp = first();
        while (!tmp->isDummy)
        {
            callback(tmp->body);
            tmp = tmp->next;
        }
    }
};

template <class T>
std::ostream &operator<<(std::ostream &os, DoublyLinkedList<T> &list)
{
    DoublyLinkedItem<T> *item = list.first();
    while (true)
    {
        os << item->body << ",";
        if (item->isDummy)
            break;
        item = item->next;
    }
    return os;
}
#endif
