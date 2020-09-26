#include <iostream>
#include <string>
#include <bitset>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"
#include "uarray.h"
#include "universal_hash.h"
#include "expectation.h"

void testkeyf()
{
    std::string teststring = "python is too slow.";
    for (std::size_t i = 0; i < teststring.size(); ++i)
    {
        std::cout << std::bitset<8>(teststring.c_str()[i]) << std::endl;
    }

    UArray<int> k = key("hello");
    std::string e = element(k);
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testkeyf();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
