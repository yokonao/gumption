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
    UArray x = tobit('p');
    std::bitset<8> b = std::bitset<8>('p');
    for (int i = 0; i < x.size(); i++)
    {
        expect(x[i] == b[i]).to_be_truthy();
    }
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testfloorlog();
    testbit();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}