#include "binary_search_tree.h"
#include <iostream>
#include <limits.h>

Dict::Dict()
{
    this->key = INT_MAX;
    this->value = "";
}

Dict::Dict(int key, std::string value)
{
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
    this->splitter = dict->body.key;
}

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int BinarySearchLeaf::maxRec(int key)
{

    if (isItem)
    {
        if (_d->body.key == key)
        {
            return 0;
        }
        else
        {
            return _d->body.key;
        }
    }
    else
    {
        return max(leftLeaf->maxRec(key), rightLeaf->maxRec(key));
    }
}

int BinarySearchLeaf::heightRec()
{
    if (isItem)
    {
        return 0;
    }
    else
    {
        return 1 + max(leftLeaf->heightRec(), rightLeaf->heightRec());
    }
}

int BinarySearchLeaf::insertRec(Dict dict, DoublyLinkedList<Dict> *list)
{
    if (isItem)
    {
        isItem = false;
        DoublyLinkedItem<Dict> *dictItem = list->insertBefore(dict, _d);
        splitter = dict.key;
        leftLeaf = new BinarySearchLeaf(dictItem);
        rightLeaf = new BinarySearchLeaf(_d);
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

int BinarySearchLeaf::removeRec(int key, DoublyLinkedList<Dict> *list)
{
    if (isItem)
    {
        list->remove(_d);
        return 0;
    }
    else
    {
        if (key <= splitter)
        {
            int dist = leftLeaf->removeRec(key, list);
            if (dist == 0)
            {
                if (rightLeaf->isItem)
                {
                    isItem = true;
                    _d = rightLeaf->_d;
                }
                else
                {
                    BinarySearchLeaf *buffLeaf = rightLeaf;
                    splitter = buffLeaf->splitter;
                    leftLeaf = buffLeaf->leftLeaf;
                    rightLeaf = buffLeaf->rightLeaf;
                }
            }
            if (key == splitter)
            {
                splitter = leftLeaf->maxRec(key);
            }

            return 1 + dist;
        }
        else
        {
            int dist = rightLeaf->removeRec(key, list);
            if (dist == 0)
            {
                if (leftLeaf->isItem)
                {
                    isItem = true;
                    _d = leftLeaf->_d;
                }
                else
                {
                    BinarySearchLeaf *buffLeaf = leftLeaf;
                    splitter = buffLeaf->splitter;
                    rightLeaf = buffLeaf->rightLeaf;
                    leftLeaf = buffLeaf->leftLeaf;
                }
            }
            return 1 + dist;
        }
    }
}

void BinarySearchLeaf::PrintRec()
{
    if (isItem)
    {
        std::cout << "{\"isItem\": true, ";
        std::cout << "\"id\": ";
        std::cout << "\"" << this << "\",";
        std::cout << "\"key\": " << _d->body.key;
        std::cout << "},";
        return;
    }

    std::cout << "{\"isItem\": false, ";
    std::cout << "\"id\": ";
    std::cout << "\"" << this << "\", ";
    std::cout << "\"key\": " << splitter << ", ";
    std::cout << "\"left\": ";
    std::cout << "\"" << leftLeaf << "\", ";
    std::cout << "\"right\": ";
    std::cout << "\"" << rightLeaf << "\"},";
    leftLeaf->PrintRec();
    rightLeaf->PrintRec();
}

BinarySearchTree::BinarySearchTree()
{
    _root = new BinarySearchLeaf(_list.head());
}

BinarySearchTree::~BinarySearchTree()
{
    delete _root;
}

void BinarySearchTree::insert(Dict dict)
{
    if (_root->insertRec(dict, &_list) > h)
    {
        h++;
    };
}

Dict BinarySearchTree::locate(int key)
{
    return _root->locateRec(key);
}

void BinarySearchTree::remove(int key)
{
    if (locate(key).key != key)
    {
        return;
    }
    else
    {
        _root->removeRec(key, &_list);
        h = _root->heightRec();
    }
}

int BinarySearchTree::height()
{
    return h;
}

void BinarySearchTree::print()
{
    std::cout << "DoublyLinkedList:" << _list << std::endl;
    printTree();
}

void BinarySearchTree::printTree()
{
    std::cout << "{\"BinarySearchTree\": ";
    std::cout << "[";
    _root->PrintRec();
    std::cout << "{}]}" << std::endl;
}
