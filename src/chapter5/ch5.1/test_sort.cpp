#include "sort.h"
#include "initial_list.h"
#include <expectation.h>

void test_SelectionSort_Good()
{
    int n = 10;
    UArray<int> a = initial_list_good(n);
    selection_sort(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void test_SelectionSort_Worst()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    selection_sort(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void test_SelectionSort_Random()
{
    for (int rep = 0; rep < 10; rep++)
    {
        int n = rep + 10;
        UArray<int> a = initial_list_random(n);
        selection_sort(a);
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            expect(a[i] >= prev).to_be_truthy();
            prev = a[i];
        }
    }
}
void test_MergeSort_Good()
{
    int n = 10;
    UArray<int> a = initial_list_good(n);
    merge_sort(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void test_MergeSort_Worst()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    std::cout << a << std::endl;
    merge_sort(a);
    std::cout << a << std::endl;
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
void test_MergeSort_Random()
{
    for (int rep = 0; rep < 10; rep++)
    {
        int n = rep + 10;
        UArray<int> a = initial_list_random(n);
        merge_sort(a);
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
    test_SelectionSort_Good();
    test_SelectionSort_Worst();
    test_SelectionSort_Random();
    test_MergeSort_Good();
    test_MergeSort_Worst();
    //test_SelectionSort_Random();
    std::cout << "ALL GREEN" << std::endl;
}