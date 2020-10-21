#include "sort.h"
#include "initial_list.h"
#include <expectation.h>

template <typename T>
void testSort()
{
    int n = 10;
    UArray<int> a = initial_list_good(n);
    T::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }

    n = 10;
    a = initial_list_worst(n);
    T::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }

    int rep = 11;
    n = rep + 10;
    a = initial_list_random(n);
    T::execute(a);
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        expect(a[i] >= prev).to_be_truthy();
        prev = a[i];
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
