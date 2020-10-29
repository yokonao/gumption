#include <uarray.h>
#include "sort.h"
#include <gen_mt.h>
#include <binary_heap.h>

void SelectionSort::execute(UArray<int> &a)
{
    int min_idx, buff;
    for (int i = 0; i < a.size(); i++)
    {
        min_idx = i;
        for (int j = i; j < a.size(); j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx == i)
        {
            continue;
        }
        else
        {
            for (int j = min_idx; j > i; j--)
            {
                buff = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buff;
            }
        }
    }
}

UArray<int> MergeSort::merge(UArray<int> a, UArray<int> b)
{
    UArray<int> c;
    int l = 0, r = 0;
    while (l < a.size() and r < b.size())
    {
        if (a[l] <= b[r])
        {
            c.pushBack(a[l]);
            l++;
        }
        else
        {
            c.pushBack(b[r]);
            r++;
        }
    }
    if (l < a.size())
    {
        for (int i = l; i < a.size(); i++)
        {
            c.pushBack(a[i]);
        }
    }
    if (r < b.size())
    {
        for (int i = r; i < b.size(); i++)
        {
            c.pushBack(b[i]);
        }
    }
    return c;
}

UArray<int> MergeSort::mergeSort(UArray<int> a)
{
    if (a.size() == 1)
    {
        return a;
    }
    UArray<int> b;
    UArray<int> c;
    for (int i = 0; i < a.size(); i++)
    {
        if (i < (a.size() / 2))
        {
            b.pushBack(a[i]);
        }
        else
        {
            c.pushBack(a[i]);
        }
    }
    return merge(mergeSort(b), mergeSort(c));
}

void MergeSort::execute(UArray<int> &a)
{
    a = mergeSort(a);
}

UArray<int> QuickSort::concat(const UArray<int> &a, const UArray<int> &b, const UArray<int> &c)
{
    UArray<int> d;
    for (int i = 0; i < a.size(); i++)
    {
        d.pushBack(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        d.pushBack(b[i]);
    }
    for (int i = 0; i < c.size(); i++)
    {
        d.pushBack(c[i]);
    }
    return d;
}

UArray<int> QuickSort::quickSort(const UArray<int> &s)
{
    if (s.size() < 1)
    {
        return s;
    }

    int p = s[gen_mt(s.size())];

    UArray<int> a, b, c;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < p)
        {
            a.pushBack(s[i]);
        }
        else if (s[i] == p)
        {
            b.pushBack(s[i]);
        }
        else
        {
            c.pushBack(s[i]);
        }
    }

    return concat(quickSort(a), b, quickSort(c));
}

void QuickSort::execute(UArray<int> &s)
{
    s = quickSort(s);
}

void InsertionSort::insertionSort(UArray<int> &a, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int e = a[i];
        if (e < a[l])
        {
            for (int j = i; j > l; j--)
            {
                a[j] = a[j - 1];
            }
            a[l] = e;
        }
        else
        {
            int j = i;
            while (a[j - 1] > e)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = e;
        }
    }
}

void InsertionSort::execute(UArray<int> &a)
{
    insertionSort(a, 0, a.size() - 1);
}

void InsertionSort::execute(UArray<int> &a, int l, int r)
{
    insertionSort(a, l, r);
}

void BinaryInsertionSort::insertionSort(UArray<int> &a, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int e = a[i];
        if (e < a[l])
        {
            for (int j = i; j > l; j--)
            {
                a[j] = a[j - 1];
            }
            a[l] = e;
        }
        else
        {
            int m = l;
            int n = i;
            while (m != n)
            {
                int mid = (m + n) / 2;
                if (a[mid] > e)
                {
                    n = mid;
                }
                else
                {
                    m = mid + 1;
                }
            }
            for (int j = i; j > m; j--)
            {
                a[j] = a[j - 1];
            }
            a[m] = e;
        }
    }
}

void BinaryInsertionSort::execute(UArray<int> &a)
{
    insertionSort(a, 0, a.size() - 1);
}

void BinaryInsertionSort::execute(UArray<int> &a, int l, int r)
{
    insertionSort(a, l, r);
}

int QSort::pickPivotPos(const UArray<int> &a, int l, int r)
{
    return l;
}
void QSort::swap(UArray<int> &a, int i, int j)
{
    int buff;
    buff = a[i];
    a[i] = a[j];
    a[j] = buff;
}
void QSort::qSort(UArray<int> &a, int l, int r)
{
    while (r - l + 1 > n_th)
    {
        int i, j;
        j = pickPivotPos(a, l, r);
        swap(a, l, j);
        int p = a[l];
        i = l;
        j = r;
        while (i <= j)
        {
            while (a[i] < p)
            {
                i++;
            }
            while (a[j] > p)
            {
                j--;
            }
            if (i <= j)
            {
                swap(a, i, j);
                i++;
                j--;
            }
        }
        if (i < (l + r) / 2)
        {
            qSort(a, l, j);
            l = i;
        }
        else
        {
            qSort(a, i, r);
            r = j;
        }
    }
    InsertionSort::execute(a, l, r);
}
void QSort::execute(UArray<int> &a)
{
    qSort(a, 0, a.size() - 1);
}

UArray<int> HeapSort::heapSort(const UArray<int> &s)
{
    UArray<int> result;
    BinaryHeapPriorityQueue pq(s.size(), s);
    for (int i = 0; i < s.size(); i++)
    {
        result.pushBack(pq.deleteMin());
    }
    return result;
}
void HeapSort::execute(UArray<int> &s)
{
    s = heapSort(s);
}