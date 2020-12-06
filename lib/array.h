#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cassert>
#include <initializer_list>
#include <iostream>

template <class T>
class Array
{
private:
    T *content;
    int n;

public:
    Array()
    {
        this->content = new T[0];
        this->n = 0;
    }

    Array(int length)
    {
        n = length;
        content = new T[n];
    }

    Array(int length, T value)
    {
        n = length;
        content = new T[n];
        for (int i = 0; i < n; i++)
        {
            content[i] = value;
        }
    }

    Array(std::initializer_list<T> init)
    {
        n = init.size();
        content = new T[n];
        int idx = 0;
        for (T t : init)
        {
            content[idx] = t;
            idx++;
        }
    }

    Array(const Array<T> &obj)
    {
        n = obj.n;
        content = new T[n];
        for (int i = 0; i < n; i++)
        {
            content[i] = obj.content[i];
        }
    }

    ~Array()
    {
        delete[] content;
    }

    Array<T> &operator=(const Array<T> &a)
    {
        if (this == &a)
            return *this;

        n = a.n;
        T *tmp = new T[n];
        for (int i = 0; i < n; i++)
        {
            tmp[i] = a.content[i];
        }
        delete[] content;
        content = tmp;
        return *this;
    }

    bool operator==(const Array<T> a)
    {
        if (n != a.n)
            return false;

        for (int i = 0; i < n; i++)
        {
            if (content[i] != a.content[i])
                return false;
        }
        return true;
    }

    inline bool operator!=(const Array<T> a)
    {
        return !(*this == a);
    }

    T &operator[](int i)
    {
        assert(i >= 0 and i < n);
        return content[i];
    };

    T &operator[](int i) const
    {
        assert(i >= 0 and i < n);
        return content[i];
    };

    int length() { return n; }
};

#endif
