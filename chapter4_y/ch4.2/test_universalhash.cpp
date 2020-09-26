#include <iostream>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"
#include "uarray.h"
#include "universal_hash.h"
#include "expectation.h"
void testkeyf()
{
    UArray k = key("hello");
    std::string e = element(k);
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testkeyf();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
