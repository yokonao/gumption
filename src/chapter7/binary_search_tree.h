#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <string>
#include <ostream>
#include <doubly_linked_list.h>

struct Dict
{
public:
    int key;
    std::string value;

    Dict();
    Dict(int key, std::string value);
    ~Dict();
};

std::ostream &operator<<(std::ostream &os, const Dict &d);

class BinarySearchLeaf
{
private:
    int splitter = 0;

public:
    bool isItem = false;
    DoublyLinkedItem<Dict> *_d = NULL;
    BinarySearchLeaf *leftLeaf = NULL;
    BinarySearchLeaf *rightLeaf = NULL;

    BinarySearchLeaf();
    ~BinarySearchLeaf();
    BinarySearchLeaf(int splitter, BinarySearchLeaf *left, BinarySearchLeaf *right);
    BinarySearchLeaf(DoublyLinkedItem<Dict> *dict);
    int insertRec(Dict dict, DoublyLinkedList<Dict> *list);
    Dict locateRec(int key);
};

class BinarySearchTree
{
private:
    int hight = 0;
    DoublyLinkedList<Dict> _list;
    BinarySearchLeaf *_root;
    //bool isEmpty;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(Dict dict);
    Dict locate(int key);
    void Print(); //debug
};

#endif