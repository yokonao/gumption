#include <uarray.h>
#include <expectation.h>
#include <iostream>

void testUArray()
{
    UArray<UArray<int>> x;
    UArray<int> y;
    y.pushBack(10);
    y.pushBack(12);
    x.pushBack(y);
    expect(x[0][1] == 12).to_be_truthy();
    y.clear();
    expect(y.size()).to_be(0);
    y.pushBack(10);
    y.pushBack(12);
    expect(y.size()).to_be(2);
    y[0] = 1;
    expect(y[0]).to_be(1);
    std::cout << y << std::endl;
}
int main()
{

    std::cout << "TEST START" << std::endl;
    testUArray();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
