#include <iostream>
#include "gen_random.h"
#include <expectation.h>
void testRandom()
{
    for (int m = 1; m < 10000; m++)
    {
        expect(gen_mt(m) < m).to_be_truthy();
        expect(0 <= gen_mt(m)).to_be_truthy();
    }
    expect_error<std::invalid_argument>([] {
        int n = gen_mt(0);
    });
    expect_error<std::invalid_argument>([] {
        int n = gen_mt(-1);
    });
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testRandom();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}