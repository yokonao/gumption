#include "graph.h"
#include <stdexcept>

namespace gmp::graph
{
    Vertex::Vertex() {}
    Vertex::~Vertex() {}

    Vertex::Vertex(int index)
    {
        this->m_index = index;
    }

    DirectedEdge::DirectedEdge() {}
    DirectedEdge::~DirectedEdge() {}

    DirectedEdge::DirectedEdge(Vertex from, Vertex to)
    {
        this->m_from = from;
        this->m_to = to;
    }

    StaticGraph::StaticGraph() { throw std::logic_error("デフォルトコンストラクタは禁止されています"); }
    StaticGraph::~StaticGraph() {}

    StaticGraph::StaticGraph(Array<Array<int>> a)
    {
        int v_count = a.length();
        int e_count = 0;
        a.foreach ([&](Array<int> array) { e_count += array.length(); });
        m_V = Array<int>(v_count + 1);
        m_E = Array<DirectedEdge>(e_count);
        int count = 0;
        m_V[count] = 0;
        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < a[i].length(); j++)
            {
                m_E[count] = DirectedEdge(i, a[i][j]);
                count++;
            }
            m_V[i + 1] = count;
        }
        m_V[a.length()] = count;
    }
}
