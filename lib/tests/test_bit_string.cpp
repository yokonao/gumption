#include "../bit_string.h"
#include "../expectation.h"
#include <string>

void testBitString()
{
    BitString b_p = BitString("p");
    int expected[] = {0, 0, 0, 0, 1, 1, 1, 0};
    int size = sizeof(expected) / sizeof(*expected);
    for (int i = 0; i < size; i++)
    {
        expect(b_p[i]).to_be(expected[i]);
    }

    expect(b_p.toString()).to_be("p");
    expect(BitString("c++").toString()).to_be("c++");
}

int main()
{
    std::cout << "TEST START" << std::endl;
    testBitString();
    std::cout << "ALL GREEN" << std::endl;

    return 0;
}
