#ifndef SORT
#define SORT

#include <uarray.h>
void selection_sort(UArray<int> &a);
void merge_sort(UArray<int> &a);

class QuickSort
{
    static UArray<int> concat(const UArray<int> &a, const UArray<int> &b, const UArray<int> &c);
    static UArray<int> quickSort(const UArray<int> &s);
public:
    static void execute(UArray<int> &s);
};

#endif
