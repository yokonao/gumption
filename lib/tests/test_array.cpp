#include <array.h>
#include <expectation.h>

void testConstructor()
{
    int N = 100;
    Array<int> a = Array<int>(N);
    for (int i = 0; i < N; i++)
    {
        expect(a[i]).to_be(0);
    }
    Array<char> b = Array<char>(N);
    for (int i = 0; i < N; i++)
    {
        expect(b[i]).to_be('\u0000');
    }
    Array<float> c = Array<float>(N);
    for (int i = 0; i < N; i++)
    {
        expect(c[i]).to_be(0.0);
    }
}

void testInitializerList()
{
    Array<int> a{1, 2, 3};
    expect(a[0]).to_be(1);
    expect(a[1]).to_be(2);
    expect(a[2]).to_be(3);
}

void testCopyConstructor()
{
    Array<int> a{1, 10, 100};
    Array<int> b = a;
    expect(a[0]).to_be(1);
    expect(a[1]).to_be(10);
    expect(a[2]).to_be(100);
    expect(b[0]).to_be(1);
    expect(b[1]).to_be(10);
    expect(b[2]).to_be(100);

    a[0] = 1000;
    expect(a[0]).to_be(1000);
    expect(a[1]).to_be(10);
    expect(a[2]).to_be(100);
    expect(b[0]).to_be(1);
    expect(b[1]).to_be(10);
    expect(b[2]).to_be(100);
}

void testAssignmentOperator()
{
    Array<int> a{1, 10, 100};
    Array<int> b{2, 20, 200};
    b = a;
    expect(b[0]).to_be(1);
    expect(b[1]).to_be(10);
    expect(b[2]).to_be(100);

    b[0] = 2000;
    expect(b[0]).to_be(2000);
    expect(a[0]).to_be(1);
}

void testForEach()
{
    Array<int> a{2, 20, 200};
    a.foreach ([](int e) {
        std::cout << e << std::endl;
    });
}

int main()
{
    executeTestSuite("コンストラクタのテスト", testConstructor);
    executeTestSuite("初期化リストを用いた初期化のテスト", testInitializerList);
    executeTestSuite("コピーコンストラクタのテスト", testCopyConstructor);
    executeTestSuite("代入演算子のテスト", testAssignmentOperator);
    executeTestSuite("foreachのテスト", testForEach);
    return 0;
}
