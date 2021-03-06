#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP
#include <array.h>
#include <initializer_list>
#include <uarray.h>

class BinaryHeapPriorityQueue
{
private:
    int n = 0;
    int w = 0;
    int flag = 0;
    Array<int> h;
    void swap(int i, int j)
    {
        int buff = h[i];
        h[i] = h[j];
        h[j] = buff;
    }

    void siftUp(int i)
    {
        if (i == 0 or h[(i - 1) / 2] <= h[i])
            return;
        swap(i, (i - 1) / 2);
        siftUp((i - 1) / 2);
    }

    void siftDownSimply(int i)
    {
        if ((i + 1) * 2 <= n)
        {
            int m = 0;

            if ((i + 1) * 2 + 1 > n)
            {
                m = i * 2 + 1;
            }
            else if (h[i * 2 + 1] <= h[(i + 1) * 2])
            {
                m = i * 2 + 1;
            }
            else
            {
                m = (i + 1) * 2;
            }

            if (h[i] > h[m])
            {
                swap(i, m);
                siftDownSimply(m);
            }
        }
    }

    void siftDownBinary(int i)
    {
        if (n <= 1)
        {
            return;
        }
        int e = h[i];
        int root = i;
        UArray<int> p;
        while ((i + 1) * 2 <= n)
        {
            int m = 0;
            if ((i + 1) * 2 + 1 > n)
            {
                m = i * 2 + 1;
            }
            else if (h[i * 2 + 1] <= h[(i + 1) * 2])
            {
                m = i * 2 + 1;
            }
            else
            {
                m = (i + 1) * 2;
            }
            p.pushBack(m);
            i = m;
        }
        if (e <= h[p[0]])
        {
            return;
        }
        int l = 0;
        int r = p.size();
        while (l != r)
        {
            int mid = (l + r) / 2;
            if (h[p[mid]] > e)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        //swap
        for (int idx = 0; idx < l; idx++)
        {
            if (idx == 0)
            {
                swap(root, p[idx]);
            }
            else
            {
                swap(p[idx - 1], p[idx]);
            }
        }
    }

    void siftDown(int i)
    {
        if (flag == 0)
        {
            siftDownSimply(i);
        }
        else
        {
            siftDownBinary(i);
        }
    }

    void heapify()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            siftDown(i);
        }
    }

public:
    BinaryHeapPriorityQueue(int w)
    {
        this->w = w;
        this->h = Array<int>(w);
    }

    BinaryHeapPriorityQueue(int w, std::initializer_list<int> init)
    {
        assert(w >= init.size());
        this->w = w;
        this->h = Array<int>(w);
        this->n = init.size();
        int idx = 0;
        for (int e : init)
        {
            h[idx] = e;
            idx++;
        }
        heapify();
    }

    BinaryHeapPriorityQueue(int w, UArray<int> a)
    {
        assert(w >= a.size());
        this->w = w;
        this->h = Array<int>(w);
        this->n = a.size();
        for (int i = 0; i < a.size(); i++)
        {
            h[i] = a[i];
        }
        heapify();
    }
    BinaryHeapPriorityQueue(int w, int flag)
    {
        this->w = w;
        this->h = Array<int>(w);
        this->flag = flag;
    }

    BinaryHeapPriorityQueue(int w, std::initializer_list<int> init, int flag)
    {
        assert(w >= init.size());
        this->w = w;
        this->h = Array<int>(w);
        this->n = init.size();
        this->flag = flag;

        int idx = 0;
        for (int e : init)
        {
            h[idx] = e;
            idx++;
        }
        heapify();
    }

    BinaryHeapPriorityQueue(int w, UArray<int> a, int flag)
    {
        assert(w >= a.size());
        this->w = w;
        this->h = Array<int>(w);
        this->n = a.size();
        this->flag = flag;
        for (int i = 0; i < a.size(); i++)
        {
            h[i] = a[i];
        }
        heapify();
    }

    int min()
    {
        assert(n > 0);
        return h[0];
    }

    void insert(int e)
    {
        assert(n < w);
        n++;
        h[n - 1] = e;
        siftUp(n - 1);
    }

    int deleteMin()
    {
        assert(n > 0);
        int result = h[0];
        h[0] = h[n - 1];
        n--;
        siftDown(0);
        return result;
    }
};
#endif
