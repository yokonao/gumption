#include "sort.h"
#include "initial_list.h"
#include <expectation.h>

template <typename T>
void checkIsSorted(UArray<int> a)
{
    T::execute(a);
    int prev = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        expect(a[i] >= prev).to_be_truthy();
        prev = a[i];
    }
}

template <typename T>
void testSort()
{
    int n = 20;
    checkIsSorted<T>(initial_list_good(n));
    checkIsSorted<T>(initial_list_worst(n));
    for (int i = 0; i < 10; i++)
    {
        checkIsSorted<T>(initial_list_random(n + i));
    }
}

int main()
{
    executeTestSuite("ソートのテスト", [] {
        testSort<SelectionSort>();
        testSort<MergeSort>();
        testSort<QuickSort>();
        testSort<InsertionSort>();
        testSort<QSort>();
    });
}
