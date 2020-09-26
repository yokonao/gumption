#include <iostream>
#include <string>
#include <bitset>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"
#include <uarray.h>
#include "universal_hash.h"
#include <expectation.h>

void testkeyf()
{
    std::string teststring = "python is too slow.";
    for (int w = 8; w < 15; w++)
    {
        UArray<UArray<int>> k = key(teststring, w);
        std::string e = element(k, w);
        expect(e == teststring).to_be_truthy();
    }
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testkeyf();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
