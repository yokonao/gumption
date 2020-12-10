#include <uarray.h>
#include <expectation.h>
#include <iostream>

void testInitializerList()
{
    UArray<int> x{1, 10, 100};
    expect(x[0]).to_be(1);
    expect(x[1]).to_be(10);
    expect(x[2]).to_be(100);

    UArray<char> y{'r', 'y', 'u'};
    expect(y[0]).to_be('r');
    expect(y[1]).to_be('y');
    expect(y[2]).to_be('u');
}

void testEquivalenceOperator()
{
    UArray<int> x;
    x.pushBack(1);
    expect(x == UArray<int>{1}).to_be_truthy();
    expect(x == UArray<int>{1, 2}).to_be_falsy();
    x.pushBack(10);
    expect(x == UArray<int>{1, 10}).to_be_truthy();
    expect(x == UArray<int>{1}).to_be_falsy();
    expect(x == UArray<int>{1, 9}).to_be_falsy();
    expect(x == UArray<int>{2, 10}).to_be_falsy();

    expect(x != UArray<int>{1, 10}).to_be_falsy();
    expect(x != UArray<int>{1}).to_be_truthy();
    expect(x != UArray<int>{1, 9}).to_be_truthy();
    expect(x != UArray<int>{2, 10}).to_be_truthy();

    expect(x).to_be_equal_to(UArray<int>{1, 10});
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

    expect(x[0]).to_be_equal_to(UArray<int>{10, 11});
    expect(y).to_be_equal_to(UArray<int>{10, 11});

    y.clear();
    expect(y.size()).to_be(0);

    y.pushBack(20);
    y.pushBack(21);
    expect(y.size()).to_be(2);
    expect(y).to_be_equal_to(UArray<int>{20, 21});
    expect(x[0]).to_be_equal_to(UArray<int>{10, 11});

    y[0] = 1;
    expect(y[0] == 1).to_be_truthy();
    expect(y).to_be_equal_to(UArray<int>{1, 21});
}

void testFill()
{
    UArray<int> a{2, 20, 200};
    a.fill(5, 3);
    a.foreach ([](int e) {
        std::cout << e << std::endl;
    });
    expect(a).to_be_equal_to(UArray<int>{3, 3, 3, 3, 3});
}

void testForEach()
{
    UArray<int> a{2, 20, 200};
    a.foreach ([](int e) {
        std::cout << e << std::endl;
    });
}

int main()
{
    executeTestSuite("初期化リストのテスト", testInitializerList);
    executeTestSuite("==演算子のテスト", testEquivalenceOperator);
    executeTestSuite("1次元配列のテスト", testUArray1D);
    executeTestSuite("2次元配列のテスト", testUArray2D);
    executeTestSuite("fillのテスト", testFill);
    executeTestSuite("foreachのテスト", testForEach);
    return 0;
}
