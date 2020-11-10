#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cassert>
#include <iostream>
#include <stack.h>

template <class T>
class Queue
{
private:
    Stack<T> inbox;
    Stack<T> outbox;
    int n;

public:
    Queue()
    {
        n = 0;
    }
    ~Queue()
    {
    }
    int size() const
    {
        return n;
    }
    bool isEmpty() const
    {
        return n == 0;
    }
    void pushBack(const T &e)
    {
        n++;
        inbox.pushBack(e);
    }
    T popFront()
    {
        assert(n > 0);
        if (outbox.isEmpty())
        {
            while (!inbox.isEmpty())
            {
                outbox.pushBack(inbox.last());
                inbox.popBack();
            }
        }
        n--;
        T res = outbox.last();
        outbox.popBack();

        return res;
    }
};
#endif
