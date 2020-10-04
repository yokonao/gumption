#include "../to_bit.h"
#include "../expectation.h"

void testToBit()
{
    UArray<int> bit = toBit("p");
    int expected[] = {0, 0, 0, 0, 1, 1, 1, 0};
    int size = sizeof(expected) / sizeof(*expected);
    for (int i = 0; i < size; i++)
    {
        std::cout << bit[i] << std::endl;
        expect(bit[i]).to_be(expected[i]);
    }
}

void testToString()
{
    expect(toString(toBit("p"))).to_be("p");
    expect(toString(toBit("c++"))).to_be("c++");
}

int main()
{
    std::cout << "TEST START" << std::endl;
    testToBit();
    testToString();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
