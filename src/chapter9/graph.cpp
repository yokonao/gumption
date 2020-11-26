#include "graph.h"

GraphNode::GraphNode()
{
    this->index = 0;
    this->nodeList = new DoublyLinkedList<int>;
}
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
    nodeList = new DoublyLinkedList<int>;
    a.nodeList->foreach([&](int e) { nodeList->pushBack(e); });
    return *this;
}

GraphNode::~GraphNode()
{
}

void GraphNode::connect(int a)
{
    int flag = 1;
    nodeList->foreach ([&](int e) {
        if(e == a)
            flag = 0;
    });
    if(!flag)
        return;
    nodeList->pushBack(a);
}

bool GraphNode::isEdge(int a)
{
    DoublyLinkedItem<int> *tmp = nodeList->head()->next;
    while (!tmp->isDummy)
    {
        if (tmp->body == a)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

UArray<int> GraphNode::next()
{
    UArray<int> res;
    DoublyLinkedItem<int> *tmp = nodeList->head()->next;
    while (!tmp->isDummy)
    {
        res.pushBack(tmp->body);
        tmp = tmp->next;
    }
    return res;
}

void GraphNode::print()
{
    std::cout << "\"";
    std::cout << index << "\"";
    std::cout << ":";
    std::cout << "[";
    DoublyLinkedItem<int> *tmp = nodeList->head()->next;
    while (!tmp->isDummy)
    {
        std::cout << tmp->body;
        tmp = tmp->next;
        if (tmp->isDummy)
            break;
        std::cout << ",";
    }
    std::cout << "]";
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

int Graph::size()
{
    return n;
}

void Graph::addEdge(int a, int b)
{
    nodeArray[a].connect(b);
    nodeArray[b].connect(a);
}

bool Graph::isEdge(int a, int b)
{
    return nodeArray[a].isEdge(b);
}

UArray<int> Graph::next(int a)
{
    return nodeArray[a].next();
}

void Graph::print()
{
    std::cout << "{\"size\":";
    std::cout << n << ",";
    std::cout << "\"content\":{";
    for (int i = 0; i < n; i++)
    {
        nodeArray[i].print();
        if (i != n - 1)
            std::cout << ",";
    }
    std::cout << "}}" << std::endl;
}
