#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <string>
#include <doubly_linked_list.h>

class KeyAndValue
{
public:
    int key;
    std::string value;
    KeyAndValue();
    KeyAndValue(int key, std::string value);
};

class BinarySearchLeafNode
{
private:
    int splitter;

public:
    bool toLeftIsLowest = false;
    bool toRightIsLowest = false;
    BinarySearchLeafNode *leftNode;
    BinarySearchLeafNode *rightNode;
    DoublyLinkedItem<KeyAndValue> *leftItem;
    DoublyLinkedItem<KeyAndValue> *rightItem;

    BinarySearchLeafNode();
    ~BinarySearchLeafNode();
    BinarySearchLeafNode(int splitter, BinarySearchLeafNode *left, BinarySearchLeafNode *right);
    BinarySearchLeafNode(int splitter, DoublyLinkedItem<KeyAndValue> *left, BinarySearchLeafNode *right);
    BinarySearchLeafNode(int splitter, BinarySearchLeafNode *left, DoublyLinkedItem<KeyAndValue> *right);
    BinarySearchLeafNode(int splitter, DoublyLinkedItem<KeyAndValue> *left, DoublyLinkedItem<KeyAndValue> *right);
};

class BinarySearchTree
{
private:
    DoublyLinkedList<KeyAndValue> _list;
    BinarySearchLeafNode *_root;
    bool isEmpty = true;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(KeyAndValue tuple);
    KeyAndValue locate(int key);
};

#endif
