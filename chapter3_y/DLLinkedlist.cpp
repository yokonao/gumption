#include "DLLinkedlist.h"
#include <iostream>
#include <cassert>
using namespace std;
Node::Node(int x,Node *p, Node *n){
        isDummy = false;
        data = x;
        prev = p;
        next = n;
}
List::List(){
    //dummyを追加
    m_head = new Node(0, NULL, NULL);
    m_head->prev = m_head;
    m_head->next = m_head;
    m_head->isDummy = true;
    size = 0;
}
int List::Size(){
    return size;
}
Node *List::head(){
    return m_head;
}
bool List::isEmpty(){
    if(m_head->next == m_head){
        return true;
    }else{
        return false;
    }
}
Node *List::first(){
    assert(isEmpty());
    return m_head->next;
}
Node *List::last(){
    assert(isEmpty());
    return m_head->prev;
}
void splice(Node *a, Node *b, Node *t){
    //assert
    Node *tmp = a->next;
    while(!tmp->isDummy){
        assert(tmp != a);
        tmp = tmp->next;
    }
    tmp = a;
    while(tmp != b){
        assert(!tmp->isDummy);
        assert(tmp != t);
        tmp = tmp->next;
    }
    assert(isvalid);

    //実行部分
    Node *ap = a->prev;
    Node *bp = b->next;
    Node *tp = t->next;
    ap->next = bp;
    bp->prev = ap;
    a->prev = t;
    b->next = tp;
    t->next = a;
    tp->prev = b;
}
//moveAfter
void List::moveAfter(Node *b, Node *ap){
    splice(b, b, ap);
}
void List::moveToFront(Node *b){
    moveAfter(b, m_head);
}
void List::moveToBack(Node *b){
    moveAfter(b, last());
}



