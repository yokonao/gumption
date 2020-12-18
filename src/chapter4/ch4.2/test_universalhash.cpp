#include <iostream>
#include <string>
#include <bitset>
#include "s_item.h"
#include "s_free_list.h"
#include <uarray.h>
#include "universal_hash.h"
#include <expectation.h>
#include "operation.h"
#include <gen_mt.h>

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
    //std::cout << hash(key("hello", w), m) << std::endl;
    //std::cout << hash(key("asdf", w), m) << std::endl;
}
void testUniversalHash()
{
    UniversalHash un;

    expect(un.find("python")).to_be("");
    un.insert("hello", "world");
    un.insert("python", "slow");
    un.insert("cpp", "fast");
    un.insert("swift", "soso");
    expect(un.find("python")).to_be("python");
    expect(un["python"]).to_be("slow");
    expect(un.find("cpp")).to_be("cpp");
    expect(un.find("swift")).to_be("swift");

    un.remove("python");
    expect(un.find("python")).to_be("");
}
void testUniversalHash_realloc()
{
    UniversalHash un;
    un.insert("hello", "world");
    un.insert("python", "slow");
    un.insert("cpp", "fast");
    un.insert("swift", "soso");

    for (int rep = 0; rep < 100; rep++)
    {
        std::string ts = "";
        for (int i = 0; i < 100; i++)
        {
            char c = 'a';
            std::string cs = "";
            c = c + gen_mt(26);
            ts = ts + c;
            cs = c;
            un.insert(ts, cs);
        }
    }
    expect(un.find("python")).to_be("python");
    expect(un["python"]).to_be("slow");
    expect(un.find("hello")).to_be("hello");
    expect(un["hello"]).to_be("world");
    expect(un.find("cpp")).to_be("cpp");
    expect(un["cpp"]).to_be("fast");
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testkeyf();
    testHash();
    testUniversalHash();
    //testUniversalHash_realloc();

    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
