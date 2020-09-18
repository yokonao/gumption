#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
Node::Node(){
    Node(int x,Node *p, Node *n){
        isDummy = false;
        data = x;
        prev = p;
        next = n;
}
List::List(){
    //dummyを追加
    head = new Node(0, NULL, NULL);
    head->prev = head;
    head->next = head;
    head->isDummy = true;
    size = 0;
}
int List::Size(){
    return size;
}
Node *List::head(){
    return head;
}
bool List::isEmpty(){
    if(head->next == head){
        return true;
    }else{
        return false;
    }
}
Node *List::first(){
    assert(isEmpty());
    return head->next;
}
Node *List::last(){
    assert(isEmpty());
    return head->prev;
}
void splice(Node *a, Node *b, Node *t){
    //assert
    Node *tmp = a;
    bool assertion = false;
    while(!tmp->isDummy || tmp != t || tmp != a){
        if(tmp == b){
            assertion = true;
            break;
        }
    }
    assert(assertion);

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
void moveAfter(Node *b, Node *ap){
    splice(b, b, ap);
}


