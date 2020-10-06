#include "gen_mt.h"
#include "expectation.h"

int main()
{
    std::cout << "TEST START" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << gen_mt(257) << std::endl;
    }
    std::cout << "ALL GREEN" << std::endl;

    return 0;
}
