#include "graph.h"
#include

void watchGraph(std::string fname, Graph &graph)
{
    std::streambuf *strbuf;
    std::string base = std::getenv("GUMPTION");
    std::ofstream ofstr(base + "/results/chapter9/" + fname);
    // 変更前の値を取得
    strbuf = std::cout.rdbuf(ofstr.rdbuf());
    // 標準出力へ出力（ファイルへ出力されます）
    graph.print();
    // 元に戻す
    std::cout.rdbuf(strbuf);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.print();

    watchGraph("graph.json", g);

    return 0;
}