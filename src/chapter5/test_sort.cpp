#include "sort.h"
#include "initial_list.h"
#include <expectation.h>

void testSelectionSortGood()
{
    int n = 10;
    UArray<int> a = initial_list_good(n);
    SelectionSort::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void testSelectionSortWorst()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    SelectionSort::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void testSelectionSortRandom()
{
    for (int rep = 0; rep < 10; rep++)
    {
        int n = rep + 10;
        UArray<int> a = initial_list_random(n);
        SelectionSort::execute(a);
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            expect(a[i] >= prev).to_be_truthy();
            prev = a[i];
        }
    }
}
void testMergeSortGood()
{
    int n = 10;
    UArray<int> a = initial_list_good(n);
    MergeSort::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void testMergeSortWorst()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    MergeSort::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void testMergeSortRandom()
{
    for (int rep = 0; rep < 10; rep++)
    {
        int n = rep + 10;
        UArray<int> a = initial_list_random(n);
        MergeSort::execute(a);
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            expect(a[i] >= prev).to_be_truthy();
            prev = a[i];
        }
    }
}
void testQuickSortGood()
{
    int n = 10;
    UArray<int> a = initial_list_good(n);
    QuickSort::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void testQuickSortWorst()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    QuickSort::execute(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void testQuickSortRandom()
{
    for (int rep = 0; rep < 10; rep++)
    {
        int n = rep + 10;
        UArray<int> a = initial_list_random(n);
        QuickSort::execute(a);
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            expect(a[i] >= prev).to_be_truthy();
            prev = a[i];
        }
    }
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testSelectionSortGood();
    testSelectionSortWorst();
    testSelectionSortRandom();
    testMergeSortGood();
    testMergeSortWorst();
    testMergeSortRandom();
    testQuickSortGood();
    testQuickSortWorst();
    testQuickSortRandom();
    std::cout << "ALL GREEN" << std::endl;
}
