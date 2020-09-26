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
    UArray x = tobit("p");
    std::bitset<8> b = std::bitset<8>('p');
    for (int i = 0; i < x.size(); i++)
    {
        expect(x[i] == b[i]).to_be_truthy();
    }
}
void testtostr()
{
    std::string ts = "python is too slow.";
    UArray x = tobit(ts);
    expect(ts == tostr(x)).to_be_truthy();
    ts = ".";
    x = tobit(ts);
    expect(ts == tostr(x)).to_be_truthy();
    ts = "Donte esta el servicio?";
    x = tobit(ts);
    expect(ts == tostr(x)).to_be_truthy();
}
void testUmul()
{
    expect_error<std::invalid_argument>([] {
        UArray x;
        UArray y;
        Umul(x, y);
    });
    expect_error<std::invalid_argument>([] {
        UArray x;
        UArray y;
        x.pushBack(10);
        x.pushBack(11);

        y.pushBack(10);

        Umul(x, y);
    });

    UArray x;
    UArray y;
    x.pushBack(10);
    y.pushBack(10);
    expect(Umul(x, y) == 100).to_be_truthy();
    x.pushBack(11);
    y.pushBack(12);
    expect(Umul(x, y) == 232).to_be_truthy();
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testfloorlog();
    testbit();
    testtostr();
    testUmul();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}