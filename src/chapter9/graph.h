#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <uarray.h>
#include <doubly_linked_list.h>

class GraphNode
{
private:
    int index;
    DoublyLinkedList<int> *nodeList;

public:
    GraphNode();
    GraphNode(int index);
    GraphNode(const GraphNode &obj);
    ~GraphNode();
    GraphNode &operator=(const GraphNode &a);
    void connect(int a);
    bool isEdge(int a);
    UArray<int> next();
    void print();
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
    Graph();
    Graph(int n);
    Graph(const Graph &obj);

    void print();
};
#endif