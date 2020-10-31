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
class QSort
{
    static const int n_th = 10;
    static int pickPivotPos(const UArray<int> &a, int l, int r);
    static void swap(UArray<int> &a, int i, int j);
    static void qSort(UArray<int> &a, int l, int r);

    static void dummy_sort(UArray<int> &a, int l, int r);

public:
    static void execute(UArray<int> &a);
};

class InsertionSort
{
    static void insertionSort(UArray<int> &a, int l, int r);

public:
    static void execute(UArray<int> &a);
    static void execute(UArray<int> &a, int l, int r);
};
class BinaryInsertionSort
{
    static void insertionSort(UArray<int> &a, int l, int r);

public:
    static void execute(UArray<int> &a);
    static void execute(UArray<int> &a, int l, int r);
};

class HeapSort
{
    static UArray<int> heapSort(const UArray<int> &s);

public:
    static void execute(UArray<int> &s);
};

class BinaryHeapSort
{
    static UArray<int> heapSort(const UArray<int> &s);

public:
    static void execute(UArray<int> &s);
};

#endif
