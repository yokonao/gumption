#ifndef FREELIST_HPP
#define FREELIST_HPP

#include "DLLinkedlist.h"
#include <iostream>
#include <cmath>
using namespace std;
class FreeList{
    private:
        static List m_List;
    public:
        static Node *head();
        static bool isEmpty();
        static void checkFreeList();
};
#endif
