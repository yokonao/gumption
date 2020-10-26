#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "sort.h"
#include "initial_list.h"

template <typename T>
void watchSort(std::string fname)
{
    double t;
    std::ofstream f;
    std::string base = std::getenv("GUMPTION");
    f.open(base + "/results/chapter5/" + fname);
    for (int n = 1; n <= 300000; n = n * 2)
    {
        std::clock_t c_start = std::clock();
        UArray<int> a = initial_list_random(n);
        T::execute(a);
        std::clock_t c_end = std::clock();
        t = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
        f << n << " " << t << std::endl;
    }
    f.close();
}
int main()
{
    watchSort<SelectionSort>("selectionsort.dat");
    watchSort<MergeSort>("mergesort.dat");
    watchSort<QuickSort>("quicksort.dat");
    watchSort<InsertionSort>("insertionsort.dat");
    watchSort<BinaryInsertionSort>("binaryinsertionsort.dat");
    watchSort<QSort>("qsort.dat");
}