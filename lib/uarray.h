#ifndef UARRAY_HPP
#define UARRAY_HPP
#include <cassert>
#include <iostream>
#include <array.h>

template <class T>
class UArray
{
private:
    int beta;
    int alpha;
    int w = 1;
    int n = 0;
    Array<T> b;

public:
    T &operator[](int i)
    {
        assert(i >= 0 and i < n);
        return b[i];
    };
    T &operator[](int i) const
    {
        assert(i >= 0 and i < n);
        return b[i];
    };
    UArray<T> &operator=(const UArray<T> &a)
    {
        if (this == &a)
            return *this;
        if (a.w <= w)
        {
            b = a.b;
            n = a.n;
            return *this;
        }
        b = a.b;
        w = a.w;
        n = a.n;
        return *this;
    }
    int size() const { return n; };
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
    void clear()
    {
        w = 1;
        n = 0;
        b = Array<T>(w);
    };
    UArray()
    {
        alpha = 4;
        beta = 2;
        b = Array<T>(1);
    };
    UArray(int al, int be)
    {
        alpha = al;
        beta = be;
        b = Array<T>(1);
    };
    UArray(const UArray &obj)
    {
        alpha = 4;
        beta = 2;
        b = obj.b;
        n = obj.n;
        w = obj.w;
    }
    ~UArray()
    {
    }
};
template <class T>
std::ostream &operator<<(std::ostream &os, const UArray<T> &ua)
{
    for (int i = 0; i < ua.size(); i++)
    {
        os << ua[i] << ",";
    }
    return os;
}

#endif
