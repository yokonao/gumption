#include <array.h>

namespace gmp::graph
{
    class Vertex
    {
    private:
        int m_index;

    public:
        Vertex();
        Vertex(int index);
        ~Vertex();
    };

    class DirectedEdge
    {
    private:
        Vertex m_from;
        Vertex m_to;

    public:
        DirectedEdge();
        DirectedEdge(Vertex from, Vertex to);
        ~DirectedEdge();
    };

    class StaticGraph
    {
    private:
        Array<DirectedEdge> m_E;
        Array<int> m_V;

    public:
        StaticGraph();
        StaticGraph(Array<Array<int>> a);
    };
}
