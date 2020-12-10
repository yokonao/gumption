#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <uarray.h>
#include <doubly_linked_list.h>
#include <stack.h>
#include <queue.h>

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
protected:
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
    Array<int> bfs(int nodeId);
    Array<int> bfsQueue(int nodeId);
    Array<int> dfsStack(int nodeId);
};

class DfsGraph : public Graph
{
private:
    UArray<bool> mark;
    int dfsPos;
    int finishingTime;
    UArray<int> dfsNum;
    UArray<int> finishTime;
    void dfs(int u, int v);
    void traverseNonTreeEdge(int u, int v);
    void traverseTreeEdge(int u, int v);
    void backtrack(int u, int v);

public:
    using Graph::Graph;
    void search(int nodeId);
};

#endif
