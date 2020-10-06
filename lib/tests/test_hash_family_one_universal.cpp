#include "hash_family_one_universal.h"
#include "expectation.h"

int main()
{
    std::cout << "TEST START" << std::endl;
    HashFamily_OneUniversal ou = HashFamily_OneUniversal(257);
    int tmp;
    tmp = ou.hash("p");
    std::cout << "p → " << tmp << std::endl;
    tmp = ou.hash("ruby");
    std::cout << "ruby → " << tmp << std::endl;
    tmp = ou.hash("python");
    std::cout << "python → " << tmp << std::endl;
    std::cout << "ALL GREEN" << std::endl;

    return 0;
}
