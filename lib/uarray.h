#ifndef UARRAY_HPP
#define UARRAY_HPP
#include <cassert>
#include <iostream>

template <class T>
class UArray
{
private:
    int beta;
    int alpha;
    int w = 1;
    int n = 0;
    T *b;

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
    int size() const { return n; };
    void pushBack(const T &e)
    {
        std::cout << "pushback" << std::endl;
        if (n == w)
        {
            reallocate(beta * n);
        }
        T element = e;
        b[n] = element;
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
        T *bp = new T[w];
        for (int i = 0; i < n; i++)
        {
            bp[i] = b[i];
        }
        delete b;
        b = bp;
    };
    void clear()
    {
        delete b;
        w = 1;
        T *bp = new T[0];
        n = 0;
        b = bp;
    };
    UArray()
    {
        alpha = 4;
        beta = 2;
        b = new T[0];
    };
    UArray(int al, int be)
    {
        alpha = al;
        beta = be;
        b = new T[0];
    };
    UArray(const UArray &obj)
    {
        std::cout << "cpy" << std::endl;

        alpha = 4;
        beta = 2;
        b = new T[obj.w];
        for (int i = 0; i < obj.n; i++)
        {
            b[i] = obj.b[i];
        }
        n = obj.n;
        w = obj.w;
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
