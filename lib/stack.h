#ifndef STACk_HPP
#define STACk_HPP

#include <cassert>
#include <iostream>
#include <array.h>

template <class T>
class Stack
{
private:
    int beta;
    int alpha;
    int w = 1;
    int n = 0;
    Array<T> b;

public:
    Stack()
    {
        alpha = 4;
        beta = 2;
        b = Array<T>(1);
    };

    ~Stack()
    {
    }

    Stack<T> &operator=(const Stack<T> &a)
    {
        if (this == &a)
            return *this;

        b = a.b;
        w = a.w;
        n = a.n;
        return *this;
    }

    int size() const
    {
        return n;
    };
    T last() const
    {
        assert(n > 0);
        return b[n - 1];
    }
    bool isEmpty() const
    {
        return n == 0;
    }
    void pushBack(const T &e)
    {
        if (n == w)
        {
            reallocate(beta * n);
        }
        b[n] = e;
        n++;
    };

    void popBack()
    {
        assert(n > 0);
        n--;
        if (alpha * n <= w and n > 0)
        {
            reallocate(beta * n);
        }
    };

    void reallocate(int wp)
    {
        w = wp;
        Array<T> bp = Array<T>(w);
        for (int i = 0; i < n; i++)
        {
            bp[i] = b[i];
        }
        b = bp;
    };

    bool find(const T &e)
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == e)
            {
                return true;
            }
        }
        return false;
    }
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &ua)
{
    for (int i = 0; i < ua.size(); i++)
    {
        os << ua[i] << ",";
    }
    return os;
}

#endif
