#include <uarray.h>
#include <expectation.h>
#include <iostream>

void testUArray1D()
{
    UArray<int> x;
    x.pushBack(1);
    expect(x.size()).to_be(1);
    expect(x[0]).to_be(1);
    x.pushBack(0);
    expect(x.size()).to_be(2);
    expect(x[1]).to_be(0);
}

void testUArray2D()
{
    UArray<UArray<int>> x;
    UArray<int> y;
    y.pushBack(10);
    y.pushBack(11);
    x.pushBack(y);
    expect(x[0][0] == 10).to_be_truthy();
    expect(x[0][1] == 11).to_be_truthy();
    expect(y[0] == 10).to_be_truthy();
    expect(y[1] == 11).to_be_truthy();
    y.clear();
    expect(y.size()).to_be(0);
    y.pushBack(20);
    y.pushBack(21);
    expect(y.size()).to_be(2);
    expect(x[0][0] == 10).to_be_truthy();
    expect(x[0][1] == 11).to_be_truthy();
    expect(y[0] == 20).to_be_truthy();
    expect(y[1] == 21).to_be_truthy();
    y[0] = 1;
    expect(y[0] == 1).to_be_truthy();
}

int main()
{
    executeTestSuite("1次元配列のテスト", testUArray1D);
    executeTestSuite("2次元配列のテスト", testUArray2D);
    return 0;
}
