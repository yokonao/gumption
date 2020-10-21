#include "sort.h"
#include "initial_list.h"
#include <expectation.h>

void checkIsSorted(UArray<int> a)
{
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
    UArray<int> a = initial_list_good(n);
    T::execute(a);
    checkIsSorted(a);

    n = 20;
    a = initial_list_worst(n);
    T::execute(a);
    checkIsSorted(a);

    int rep = 11;
    n = rep + 10;
    a = initial_list_random(n);
    T::execute(a);
    checkIsSorted(a);
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
