#include <uarray.h>
#include "sort.h"
#include "gen_random.h"


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
