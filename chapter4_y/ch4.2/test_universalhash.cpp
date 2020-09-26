#include <iostream>
#include <string>
#include <bitset>
#include "s_item.h"
#include "s_linked_list.h"
#include "s_free_list.h"
#include <uarray.h>
#include "universal_hash.h"
#include <expectation.h>
#include "operation.h"

void testkeyf()
{
    std::string teststring = "pythonistooslow";
    for (int w = 8; w < 15; w++)
    {
        UArray<UArray<int>> k = key(teststring, w);
        std::string e = element(k, w);
        expect(e == teststring).to_be_truthy();
    }
}
void testHash()
{
    int m = 257;
    int w = floorlog(m);
    expect(hash(key("hello", w), m) == hash(key("hello", w), m)).to_be_truthy();
    std::cout << hash(key("hello", w), m) << std::endl;
    std::cout << hash(key("asdf", w), m) << std::endl;
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testkeyf();
    testHash();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
