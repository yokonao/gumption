#include <iostream>
#include <bitset>
#include "operation.h"
#include "uarray.h"
#include <expectation.h>

void testfloorlog()
{
    expect(floorlog(257) == 8).to_be_truthy();
    expect(floorlog(17) == 4).to_be_truthy();
    expect_error<std::invalid_argument>([] {
        floorlog(0);
    });
}
void testbit()
{
    UArray<int> x = tobit("p");
    std::bitset<8> b = std::bitset<8>('p');
    for (int i = 0; i < x.size(); i++)
    {
        expect(x[i] == b[i]).to_be_truthy();
    }
}
void testtostr()
{
    std::string ts = "python is too slow.";
    UArray<int> x = tobit(ts);
    expect(ts == tostr(x)).to_be_truthy();
    ts = ".";
    x = tobit(ts);
    expect(ts == tostr(x)).to_be_truthy();
    ts = "py";     //0111000....
    x = tobit(ts); //[1001111000001110]インデックスが二進数の桁に対応する
    expect(ts == tostr(x)).to_be_truthy();

    ts = "Donte esta el servicio?";
    x = tobit(ts);
    expect(ts == tostr(x)).to_be_truthy();
}
void testUmul()
{
    expect_error<std::invalid_argument>([] {
        UArray<int> x;
        UArray<int> y;
        Umul(x, y);
    });
    expect_error<std::invalid_argument>([] {
        UArray<int> x;
        UArray<int> y;
        x.pushBack(10);
        x.pushBack(11);

        y.pushBack(10);

        Umul(x, y);
    });

    UArray<int> x;
    UArray<int> y;
    x.pushBack(10);
    y.pushBack(10);
    expect(Umul(x, y) == 100).to_be_truthy();
    x.pushBack(11);
    y.pushBack(12);
    expect(Umul(x, y) == 232).to_be_truthy();
}
void testUArray()
{
    UArray<UArray<int>> x;
    UArray<int> y;
    y.pushBack(10);
    y.pushBack(12);
    x.pushBack(y);
    expect(x[0][1] == 12).to_be_truthy();
}
void testfindk()
{
    expect(findk(8)).to_be(2);
    expect(findk(9)).to_be(2);
    expect(findk(27)).to_be(3);
    expect(findk(130)).to_be(5);
}
void testfindPrime()
{
    expect(findPrime(8)).to_be(521);
    expect(findPrime(7)).to_be(347);

    expect(findPrime(9)).to_be(733);
    expect(findPrime(27)).to_be(19687);
    expect(findPrime(131)).to_be(2248117);
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testfloorlog();
    testbit();
    testtostr();
    testUmul();
    testUArray();
    testfindk();
    testfindPrime();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}