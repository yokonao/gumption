#include <array.h>

namespace gmp::graph
{
    class Vertex
    {
    protected:
        int m_index;

    public:
        Vertex();
        Vertex(int index);
        ~Vertex();
    };

    class DirectedEdge
    {
    protected:
        Vertex m_from;
        Vertex m_to;

    public:
        DirectedEdge();
        DirectedEdge(Vertex from, Vertex to);
        ~DirectedEdge();
    };

    class StaticGraph
    {
    protected:
        Array<DirectedEdge> m_E;
        Array<int> m_V;

    public:
        StaticGraph();
        StaticGraph(Array<Array<int>> a);
        ~StaticGraph();
    };
}
