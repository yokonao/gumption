#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
class Node{
    public:
    int data;
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
        size = 0;
    }
    int Size(){
        return size;
    }
};
void splice(Node *a, Node *b, Node *t){
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

