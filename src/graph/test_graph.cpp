#include <expectation.h>
#include "graph.h"

namespace gmp::extension::test
{
    using namespace gmp::graph;
    class StaticGraph : gmp::graph::StaticGraph
    {
    public:
        using gmp::graph::StaticGraph::StaticGraph;
        int vertex_count()
        {
            return m_V.length() - 1;
        }
        int edge_count()
        {
            return m_E.length();
        }
    };
}

void testGraphDefaultConstructer()
{
    expect_error<std::logic_error>([]() {
        gmp::graph::StaticGraph g;
    });
}

void testGraphSimple()
{
    namespace test = gmp::extension::test;
    test::StaticGraph g(Array<Array<int>>{Array<int>{1}, Array<int>{0}});
    expect(g.edge_count()).to_be(2);
    expect(g.vertex_count()).to_be(2);

    // P204第一行右側の図
    test::StaticGraph g2(Array<Array<int>>{Array<int>{1, 3}, Array<int>{0, 2, 3}, Array<int>{1, 3}, Array<int>{0, 1, 2}});
    expect(g2.edge_count()).to_be(10);
    expect(g2.vertex_count()).to_be(4);
}

int main()
{
    executeTestSuite("DefaultConstructerのテスト", testGraphDefaultConstructer);
    executeTestSuite("グラフのテストSimple", testGraphSimple);
    return 0;
}
