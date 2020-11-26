#include <expectation.h>
#include "node_array.h"

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

int main()
{
    executeTestSuite("グラフのテストSimple", testGraphSimple);
    return 0;
}
