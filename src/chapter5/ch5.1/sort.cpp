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
