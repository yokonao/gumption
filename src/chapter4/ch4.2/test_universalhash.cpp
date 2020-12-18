#include <iostream>
#include <string>
#include <s_linked_list.h>
#include <uarray.h>
#include "universal_hash.h"
#include <expectation.h>
#include <gen_mt.h>


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
void testUniversalHashRealloc()
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
    executeTestSuite("ハッシュのテスト", testUniversalHash);
    executeTestSuite("再割付のテスト", testUniversalHashRealloc);
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
