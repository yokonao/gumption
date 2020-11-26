#ifndef NODE_ARRAY_HPP
#define NODE_ARRAY_HPP
#include <uarray.h>
#include <doubly_linked_list.h>

class GraphNode
{
private:
    int index;
    DoublyLinkedList<int> *nodeList;

public:
    GraphNode(int index);
    GraphNode(const GraphNode &obj);
    GraphNode &operator=(const GraphNode &a);
    void connect(int a);
    bool isEdge(int a);
    UArray<int> next();
};

class Graph
{
private:
    int n;
    UArray<GraphNode> nodeArray;

public:
    int size();
    void addEdge(int a, int b);
    bool isEdge(int a, int b);
    UArray<int> next(int a);
    Graph(int n);
};
#endif