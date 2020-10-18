#ifndef SORT_HPP
#define SORT_HPP

#include <uarray.h>

class SelectionSort
{
public:
    static void execute(UArray<int> &a);
};

class MergeSort
{
    static UArray<int> merge(UArray<int> a, UArray<int> b);
    static UArray<int> mergeSort(UArray<int> a);

public:
    static void execute(UArray<int> &a);
};

class QuickSort
{
    static UArray<int> concat(const UArray<int> &a, const UArray<int> &b, const UArray<int> &c);
    static UArray<int> quickSort(const UArray<int> &s);

public:
    static void execute(UArray<int> &s);
};

#endif
