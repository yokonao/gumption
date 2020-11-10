#include "binary_search_tree.h"

KeyAndValue::KeyAndValue() {}

KeyAndValue::KeyAndValue(int key, std::string value)
{
    this->key = key;
    this->value = value;
}

BinarySearchLeafNode::BinarySearchLeafNode() {}

BinarySearchLeafNode::~BinarySearchLeafNode() {}

BinarySearchLeafNode::BinarySearchLeafNode(int splitter, BinarySearchLeafNode *left, BinarySearchLeafNode *right)
{
    this->splitter = splitter;
    this->leftNode = left;
    this->rightNode = right;
}

BinarySearchLeafNode::BinarySearchLeafNode(int splitter, DoublyLinkedItem<KeyAndValue> *left, BinarySearchLeafNode *right)
{
    this->splitter = splitter;
    this->leftItem = left;
    this->rightNode = right;
    this->toLeftIsLowest = true;
}

BinarySearchLeafNode::BinarySearchLeafNode(int splitter, BinarySearchLeafNode *left, DoublyLinkedItem<KeyAndValue> *right)
{
    this->splitter = splitter;
    this->leftNode = left;
    this->rightItem = right;
    this->toRightIsLowest = true;
}

BinarySearchLeafNode::BinarySearchLeafNode(int splitter, DoublyLinkedItem<KeyAndValue> *left, DoublyLinkedItem<KeyAndValue> *right)
{
    this->splitter = splitter;
    this->leftItem = left;
    this->rightItem = right;
    this->toLeftIsLowest = true;
    this->toRightIsLowest = true;
}

BinarySearchTree::BinarySearchTree() {}

BinarySearchTree::~BinarySearchTree() {}

void BinarySearchTree::insert(KeyAndValue tuple)
{
    if (isEmpty)
    {
        DoublyLinkedItem<KeyAndValue> *node = _list.insertAfter(tuple, _list.head());
        _root = new BinarySearchLeafNode(tuple.key, node, _list.head());
        isEmpty = false;
    }
    else
    {
    }
}
