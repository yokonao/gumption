#include <uarray.h>

void selection_sort(UArray<int> &a)
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
};
UArray<int> merge(UArray<int> a, UArray<int> b)
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
UArray<int> divide(UArray<int> a)
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
    return merge(b, c);
}
void merge_sort(UArray<int> &a)
{
    a = divide(a);
}
