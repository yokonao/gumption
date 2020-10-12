#include "selection_sort.h"
#include "initial_list.h"
#include <expectation.h>

void test_SelectionSort()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    SelectionSort::sort(a);
}
int main()
{
    test_SelectionSort();
}