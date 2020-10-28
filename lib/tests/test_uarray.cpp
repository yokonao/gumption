#include <uarray.h>
#include <expectation.h>
#include <iostream>

void testEquivalenceOperator()
{
    UArray<int> x;
    x.pushBack(1);
    expect(x == std::array<int, 1>{1}).to_be_truthy();
    expect(x == std::array<int, 2>{1, 2}).to_be_falsy();
    x.pushBack(10);
    expect(x == std::array<int, 2>{1, 10}).to_be_truthy();
    expect(x == std::array<int, 1>{1}).to_be_falsy();
    expect(x == std::array<int, 2>{1, 9}).to_be_falsy();
    expect(x == std::array<int, 2>{2, 10}).to_be_falsy();

    expect(x != std::array<int, 2>{1, 10}).to_be_falsy();
    expect(x != std::array<int, 1>{1}).to_be_truthy();
    expect(x != std::array<int, 2>{1, 9}).to_be_truthy();
    expect(x != std::array<int, 2>{2, 10}).to_be_truthy();

    expect(x).to_be_equal_to(std::array<int, 2>{1, 10});
}

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
    
    expect(x[0]).to_be_equal_to(std::array<int, 2>{10, 11});
    expect(y).to_be_equal_to(std::array<int, 2>{10, 11});

    y.clear();
    expect(y.size()).to_be(0);
    
    y.pushBack(20);
    y.pushBack(21);
    expect(y.size()).to_be(2);
    expect(y).to_be_equal_to(std::array<int, 2>{20, 21});
    expect(x[0]).to_be_equal_to(std::array<int, 2>{10, 11});

    y[0] = 1;
    expect(y[0] == 1).to_be_truthy();
    expect(y).to_be_equal_to(std::array<int, 2>{1, 21});
}

int main()
{
    executeTestSuite("==演算子のテスト", testEquivalenceOperator);
    executeTestSuite("1次元配列のテスト", testUArray1D);
    executeTestSuite("2次元配列のテスト", testUArray2D);
    return 0;
}
