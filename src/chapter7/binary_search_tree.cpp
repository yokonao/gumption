#include "binary_search_tree.h"
#include <iostream>
#define INF 100000000

Dict::Dict()
{
    this->key = 0;
    this->value = "";
}
Dict::Dict(int key, std::string value)
{
    assert(key <= INF);
    this->key = key;
    this->value = value;
}
Dict::~Dict() {}
std::ostream &operator<<(std::ostream &os, const Dict &d)
{
    os << "(" << d.key << ", ";
    os << d.value << ") ";
    return os;
}
BinarySearchLeaf::BinarySearchLeaf() {}

BinarySearchLeaf::~BinarySearchLeaf() {}

BinarySearchLeaf::BinarySearchLeaf(int splitter, BinarySearchLeaf *left, BinarySearchLeaf *right)
{
    this->splitter = splitter;
    this->leftLeaf = left;
    this->rightLeaf = right;
}

BinarySearchLeaf::BinarySearchLeaf(DoublyLinkedItem<Dict> *dict)
{
    this->isItem = true;
    this->_d = dict;
}

int BinarySearchLeaf::insertRec(Dict dict, DoublyLinkedList<Dict> *list)
{
    if (isItem)
    {
        isItem = false;
        if (dict.key <= _d->body.key)
        {
            DoublyLinkedItem<Dict> *dictItem = list->insertBefore(dict, _d);
            splitter = dict.key;
            leftLeaf = new BinarySearchLeaf(dictItem);
            rightLeaf = new BinarySearchLeaf(_d);
        }
        else
        {
            splitter = _d->body.key;
            DoublyLinkedItem<Dict> *dictItem = list->insertAfter(dict, _d);
            leftLeaf = new BinarySearchLeaf(_d);
            rightLeaf = new BinarySearchLeaf(dictItem);
        }
        return 1;
    }
    else
    {
        if (dict.key <= splitter)
        {
            return 1 + leftLeaf->insertRec(dict, list);
        }
        else
        {
            return 1 + rightLeaf->insertRec(dict, list);
        }
    }
}

Dict BinarySearchLeaf::locateRec(int key)
{
    if (isItem)
    {
        return _d->body;
    }
    else
    {
        if (key <= splitter)
        {
            return leftLeaf->locateRec(key);
        }
        else
        {
            return rightLeaf->locateRec(key);
        }
    }
}

BinarySearchTree::BinarySearchTree()
{
    // key:infinityのNodeを作成
    Dict _d(INF, ""); //todo:infinityで置き換える
    DoublyLinkedItem<Dict> *item = _list.insertAfter(_d, _list.head());
    _root = new BinarySearchLeaf(item);
}

BinarySearchTree::~BinarySearchTree() {}

void BinarySearchTree::insert(Dict dict)
{
    //DoublyLinkedItem<Dict> *item = _list.insertAfter(d, _list.head());
    //_root = new BinarySearchLeaf(d.key, item, _list.head());
    //isEmpty = false;
    if (_root->insertRec(dict, &_list) > h)
    {
        h++;
    };
}

Dict BinarySearchTree::locate(int key)
{
    return _root->locateRec(key);
}

int BinarySearchTree::height()
{
    return h;
}

void BinarySearchTree::Print()
{
    std::cout << "DoublyLinkedList:" << _list << std::endl;
    //std::cout << "BinarySearchTree:" << _root->splitter << std::endl;
    // todo: 木構造のプリント
}
