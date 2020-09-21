#include <iostream>
#include <cassert>
#include <time.h>
#include "uarray.h"

void test()
{
    UArray ua(4, 2);
    assert(ua.size() == 0);
    ua.pushBack(1);
    assert(ua[0] == 1);
    ua.pushBack(10);
    assert(ua[0] == 1 && ua[1] == 10);
    ua.pushBack(100);
    assert(ua[0] == 1 && ua[1] == 10 && ua[2] == 100);
    assert(ua.size() == 3);
    ua.popBack();
    assert(ua[0] == 1 && ua[1] == 10);
    ua.popBack();
    assert(ua[0] == 1);
    ua.popBack();
    assert(ua.size() == 0);
}
void pushpop(int m, int al){
    UArray ua(al, 2);
    for(int i=0;i<m;i++){
        ua.pushBack(10);
    }
    for(int i=0;i<m;i++){
        ua.popBack();
    }
}
int main()
{
    clock_t t;
    double dt;
    for(int i=1;i <= 65536;i=i*2){
        t = clock();
        pushpop(100, 2);
        dt = (double)(clock() - t)/CLOCKS_PER_SEC;
        std::cout << i << " "<< dt <<std::endl;
    }
    return 0;
}