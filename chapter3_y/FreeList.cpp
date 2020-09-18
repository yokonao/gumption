#include "DLLinkedlist.h"
#include <iostream>
#include <cmath>
using namespace std;

List FreeList::m_List = new List();
Node *FreeList::head(){return m_List.head();}
bool FreeList::isEmpty(){return m_List.isEmpty();}
void FreeList::checkFreeList(){
    if(isEmpty()){
        Node *h = m_List.head();
        Node *first = new Node(0, h, h);
        h->next = first;
        h->prev = first;
    }
}
