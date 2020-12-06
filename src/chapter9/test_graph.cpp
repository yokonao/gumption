#include <expectation.h>
#include "graph.h"

void testGraphSimple()
{
    Graph g(3);
    g.addEdge(0, 1);
    expect(g.isEdge(0, 1)).to_be_truthy();
    expect(g.isEdge(1, 0)).to_be_truthy();
    expect(g.isEdge(0, 2)).to_be_falsy();
    expect(g.isEdge(2, 0)).to_be_falsy();
    expect(g.isEdge(1, 2)).to_be_falsy();
    expect(g.isEdge(2, 1)).to_be_falsy();
}

void testGraphNormal()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    expect(g.isEdge(0, 1)).to_be_truthy();
    expect(g.isEdge(1, 0)).to_be_truthy();
    expect(g.isEdge(0, 2)).to_be_truthy();
    expect(g.isEdge(2, 0)).to_be_truthy();
    expect(g.isEdge(1, 2)).to_be_falsy();
    expect(g.isEdge(2, 1)).to_be_falsy();
}

void testBreadthFirstSearch()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.bfs(0);
}

int main()
{
    executeTestSuite("グラフのテストSimple", testGraphSimple);
    executeTestSuite("グラフのテストNormal", testGraphNormal);
    executeTestSuite("深さ優先探索のテスト", testBreadthFirstSearch);
    return 0;
}
