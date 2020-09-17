#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
class Node{
    public:
    int data;
    bool isDummy = false;
    Node *prev, *next;
    Node(int x,Node *p, Node *n){
        data = x;
        prev = p;
        next = n;
    }
};
class List{
    private:
    Node *head;
    int size;
    public:
    List(){
        //dummyを追加
        head = new Node(0, NULL, NULL);
        head->prev = head;
        head->next = head;
        head->isDummy = true;
        size = 0;
    }
    int Size(){
        return size;
    }
    Node head(){
        return head;
    }
    bool isEmpty(){
        if(head->next == head){
            return true;
        }else{
            return false;
        }
    }
    Node first(){
        assert(isEmpty());
        return head->next;
    }
    Node last(){
        assert(isEmpty());
        return head->prev;
    }
};
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
int main(){
    List l;
    cout << l.Size() << endl;
    return 0;
}

