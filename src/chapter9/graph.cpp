#include "graph.h"
#include <limits.h>

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
    a.nodeList->foreach ([&](int e) { nodeList->pushBack(e); });
    return *this;
}

GraphNode::~GraphNode()
{
}

void GraphNode::connect(int a)
{
    bool connected = false;
    nodeList->foreach ([&](int e) {
        connected |= (e == a);
    });
    if (connected)
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

void Graph::bfs(int nodeId)
{
    Array<int> d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
    }
    Array<bool> searched(n);

    d[nodeId] = 0;
    searched[nodeId] = true;
    UArray<int> attentionLayer;
    UArray<int> nextLayer;
    attentionLayer.pushBack(nodeId);

    int l = 1;
    while (attentionLayer.size() != 0)
    {
        for (int i = 0; i < attentionLayer.size(); i++)
        {
            UArray<int> nextNodes = nodeArray[attentionLayer[i]].next();
            for (int j = 0; j < nextNodes.size(); j++)
            {
                if (!searched[nextNodes[j]])
                {
                    nextLayer.pushBack(nextNodes[j]);
                    d[nextNodes[j]] = l;
                    searched[nextNodes[j]] = true;
                }
            }
        }
        attentionLayer = nextLayer;
        nextLayer.clear();
        l++;
    }

    std::cout << "start node: " << nodeId << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << i << ": " << d[i] << std::endl;
    }
}
