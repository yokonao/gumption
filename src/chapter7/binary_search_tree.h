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
    bool toLeftIsLowest = false;
    bool toRightIsLowest = false;
    BinarySearchLeafNode *leftNode;
    BinarySearchLeafNode *rightNode;
    DoublyLinkedItem<KeyAndValue> *leftItem;
    DoublyLinkedItem<KeyAndValue> *rightItem;

public:
    BinarySearchLeafNode();
    ~BinarySearchLeafNode();
    BinarySearchLeafNode(BinarySearchLeafNode *left, BinarySearchLeafNode *right);
    BinarySearchLeafNode(DoublyLinkedItem<KeyAndValue> *left, BinarySearchLeafNode *right);
    BinarySearchLeafNode(BinarySearchLeafNode *left, DoublyLinkedItem<KeyAndValue> *right);
    BinarySearchLeafNode(DoublyLinkedItem<KeyAndValue> *left, DoublyLinkedItem<KeyAndValue> *right);
};

class BinarySearchTree
{
private:
    DoublyLinkedList<KeyAndValue> _list;
    BinarySearchLeafNode _root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
};

#endif
