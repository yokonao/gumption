#include <iostream>

class LL
{
public:
    int data;
    LL *prev;
    LL *next;

    LL(){
        data = 1;
        prev = this;
        next = this;
    }
};

int main()
{
    LL l;
    LL n = *l.next;
    std::cout << l.data << std::endl;
    std::cout << n.data << std::endl;
    return 0;
}
