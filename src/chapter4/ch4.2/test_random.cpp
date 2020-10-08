#include <iostream>
#include "gen_random.h"
#include <expectation.h>
#include "rand_list.h"
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
void testRandList()
{
    RandList::pushBack(10);
    expect(RandList::size() == 1).to_be_truthy();
}
void testRandListRecalc()
{
    RandList::pushBack(10);
    RandList::recalc(10);
    expect(RandList::size()).to_be(10);
    RandList::recalc(1);
    expect(RandList::size()).to_be(1);
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testRandom();
    testRandList();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}