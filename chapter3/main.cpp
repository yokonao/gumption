#include <iostream>
#include "linked_list.h"

int main()
{
    LL l_dummy;
    LL l1(1, &l_dummy, &l_dummy);
    std::cout << l_dummy.data << std::endl;
    std::cout << l1.data << std::endl;
    return 0;
}
