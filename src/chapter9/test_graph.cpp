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
void testGraphNext()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 1);
    g.addEdge(2, 4);
    UArray<int> v = g.next(0);
    UArray<int> w = g.next(2);

    expect(v).to_be_equal_to(UArray<int>{1, 2});
    expect(w).to_be_equal_to(UArray<int>{0, 4});
}
void testGraphDefaultConstructer()
{
    Graph g;
    expect(g.size()).to_be(0);
}
void testGraphCopyConstructer()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 1);
    g.addEdge(2, 4);
    Graph h = g;
    g.addEdge(0, 3);
    UArray<int> v = g.next(0);
    UArray<int> w = g.next(2);

    expect(v).to_be_equal_to(UArray<int>{1, 2, 3});
    expect(w).to_be_equal_to(UArray<int>{0, 4});

    UArray<int> x = h.next(0);
    UArray<int> y = h.next(2);

    expect(x).to_be_equal_to(UArray<int>{1, 2});
    expect(y).to_be_equal_to(UArray<int>{0, 4});
}
int main()
{
    executeTestSuite("グラフのテストSimple", testGraphSimple);
    executeTestSuite("グラフのテストNormal", testGraphNormal);
    executeTestSuite("nextのテスト", testGraphNext);
    executeTestSuite("DefaultConstructerのテスト", testGraphDefaultConstructer);
    executeTestSuite("CopyConstructrのテスト", testGraphCopyConstructer);
    return 0;
}
