#include "hash_family_one_universal.h"
#include "expectation.h"

void testHashForString()
{
    std::cout << "TEST START" << std::endl;
    HashFamily_OneUniversal<std::string> ou = HashFamily_OneUniversal<std::string>(257);
    int tmp;
    tmp = ou.hash("p");
    std::cout << "p → " << tmp << std::endl;
    tmp = ou.hash("ruby");
    std::cout << "ruby → " << tmp << std::endl;
    tmp = ou.hash("python");
    std::cout << "python → " << tmp << std::endl;
    std::cout << "ALL GREEN" << std::endl;
}

int main()
{
    executeTestSuite("std::stringのハッシュ関数", testHashForString);
    return 0;
}
