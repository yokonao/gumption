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
};
void splice(Node *a, Node *b, Node *t){
    Node *tmp = a;
    bool assertion = false;
    while(!tmp->isDummy || tmp != t || tmp != a){
        if(tmp == b){
            assertion = true;
            break;
        }
    }
    assert(assertion);
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
int main(){
    List l;
    cout << l.Size() << endl;
    return 0;
}

