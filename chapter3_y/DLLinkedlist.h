#ifndef DLLINKEDLIST_HPP
#define DLLINKEDLIST_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
class Node{
    public:
        int data;
        bool isDummy;
        Node *prev, *next;
        Node(int x,Node *p, Node *n);
};
class List{
    private:
        Node *head;
        int size;
    public:
        List();
        int Size();
        Node *head();
        bool isEmpty();
        Node *first();
        Node *last();
        void moveAfter(Node *b, Node *ap);

};

#endif
