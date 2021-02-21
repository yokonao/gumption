#include <expectation.h>
#include "graph.h"

using namespace gmp::graph;

void testGraphDefaultConstructer()
{
    StaticGraph g;
}

void testGraphSimple()
{
    StaticGraph g(Array<Array<int>>{Array<int>{1}, Array<int>{0}});
}


int main()
{
    executeTestSuite("DefaultConstructerのテスト", testGraphDefaultConstructer);
    executeTestSuite("グラフのテストSimple", testGraphSimple);
    return 0;
}
