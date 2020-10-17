#include "selection_sort.h"
#include "initial_list.h"
#include <expectation.h>

void test_SelectionSort()
{
    int n = 10;
    UArray<int> a = initial_list_worst(n);
    selection_sort(a);
    for (int i = 1; i <= n; i++)
    {
        expect(a[i - 1]).to_be(i);
    }
}
int main()
{
    std::cout << "TEST START" << std::endl;
    test_SelectionSort();

    std::cout << "ALL GREEN" << std::endl;
}