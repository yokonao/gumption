#include <uarray.h>
#include <expectation.h>
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
    y.print();
}
int main()
{
    testUArray();
}