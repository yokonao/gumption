#include "node_array.h"

GraphNode::GraphNode(int index)
{
    this->index = index;
    this->nodeList = new DoublyLinkedList<int>;
}

GraphNode::GraphNode(const GraphNode &obj)
{
    index = obj.index;
    nodeList = obj.nodeList;
}

GraphNode &GraphNode::operator=(const GraphNode &a)
{
    if (this == &a)
    {
        return *this;
    }
    index = a.index;
    nodeList = a.nodeList;
    return *this;
}

void GraphNode::connect(int a)
{
    DoublyLinkedItem<int> *tmp = nodeList->first();
    while (!tmp->isDummy)
    {
        if (tmp->body == a)
        {
            return;
        }
        tmp = tmp->next;
    }
    nodeList->pushBack(a);
}

UArray<int> GraphNode::next()
{
    UArray<int> res;
    DoublyLinkedItem<int> *tmp = nodeList->first();
    while (!tmp->isDummy)
    {
        res.pushBack(tmp->body);
        tmp = tmp->next;
    }
    return res;
}

Graph::Graph(int n)
{
    this->n = n;
    for (int i = 0; i < n; i++)
    {
        GraphNode node(i);
        this->nodeArray.pushBack(node);
    }
}

void Graph::addEdge(int a, int b)
{
    nodeArray[a].connect(b);
    nodeArray[b].connect(a);
}

UArray<int> Graph::next(int a)
{
    return nodeArray[a].next();
}