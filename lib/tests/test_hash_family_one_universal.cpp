#include "hash_family_one_universal.h"
#include "expectation.h"

void testHashForInt()
{
    HashFamily_OneUniversal<int> ou = HashFamily_OneUniversal<int>(257);
    expect(ou.hash(1)).to_be(1);
    expect(ou.hash(33)).to_be(33);
    expect(ou.hash(260)).to_be(3);
}

void testHashForString()
{
    HashFamily_OneUniversal<std::string> ou = HashFamily_OneUniversal<std::string>(257);
    int tmp;
    tmp = ou.hash("p");
    std::cout << "p → " << tmp << std::endl;
    tmp = ou.hash("ruby");
    std::cout << "ruby → " << tmp << std::endl;
    tmp = ou.hash("python");
    std::cout << "python → " << tmp << std::endl;
}

int main()
{
    std::cout << "TEST START" << std::endl;
    executeTestSuite("intのハッシュ関数", testHashForInt);
    executeTestSuite("std::stringのハッシュ関数", testHashForString);
    std::cout << "ALL GREEN" << std::endl;

    return 0;
}
