#include <iostream>
#include "item.h"
#include "linked_list.h"

int main()
{
    LinkedList ll;
    std::cout << ll.head() << std::endl;
    std::cout << ll.head()->next << std::endl;
    std::cout << ll.head()->prev << std::endl;
    std::cout << ll.isEmpty() << std::endl;
    return 0;
}
