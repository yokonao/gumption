#include <iostream>
#include "item.h"

int main()
{
    Item<int> dum;
    Item<int> item(1, &dum, &dum);
    std::cout << dum.e << std::endl;
    std::cout << item.e << std::endl;
    return 0;
}
