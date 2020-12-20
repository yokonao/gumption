#include <iostream>
#include <expectation.h>
#include <chaining_hash.h>

void testChainingHash()
{
    ChainingHash<std::string, std::string> un;
    un.insert("hello", "world");
    un.insert("python", "slow");
    un.insert("cpp", "fast");
    un.insert("swift", "soso");
    expect(un.find("python")).to_be("python");
    expect(un["python"]).to_be("slow");
    expect(un.find("cpp")).to_be("cpp");
    expect(un.find("swift")).to_be("swift");
}

void testChainingHashRealloc()
{
    ChainingHash<std::string, std::string> un;
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

void testKeyNotFoundError()
{
    ChainingHash<std::string, std::string> un;
    un.insert("hello", "world");
    un.insert("python", "slow");
    un.insert("cpp", "fast");
    un.insert("swift", "soso");
    expect(un.find("python")).to_be("python");
    expect(un["python"]).to_be("slow");
    expect(un.find("cpp")).to_be("cpp");
    expect(un.find("swift")).to_be("swift");
    expect_error<std::runtime_error>([&] {
        un.find("ruby");
    });
    expect_error<std::runtime_error>([&] {
        un["ruby"];
    });
}

void testRemove()
{
    ChainingHash<std::string, std::string> un;
    un.insert("hello", "world");
    un.insert("python", "slow");
    un.insert("cpp", "fast");
    un.insert("swift", "soso");
    expect(un.find("python")).to_be("python");
    expect(un["python"]).to_be("slow");
    expect(un.find("cpp")).to_be("cpp");
    expect(un.find("swift")).to_be("swift");
    un.remove("hello");
    expect_error<std::runtime_error>([&] {
        un.find("hello");
    });
    un.remove("python");
    expect_error<std::runtime_error>([&] {
        un.find("python");
    });
    un.remove("cpp");
    expect_error<std::runtime_error>([&] {
        un.find("cpp");
    });
    un.remove("swift");
    expect_error<std::runtime_error>([&] {
        un.find("swift");
    });
}

int main()
{
    std::cout << "TEST START" << std::endl;
    executeTestSuite("ハッシュ(文字列, 文字列)のテスト", testChainingHash);
    executeTestSuite("再割付のテスト", testChainingHashRealloc);
    executeTestSuite("キーが存在しない時のエラーのテスト", testKeyNotFoundError);
    executeTestSuite("削除のテスト", testRemove);
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
