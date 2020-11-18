#include "binary_search_tree.h"
#include <iostream>
#include <fstream>

void watchTree(std::string fname, BinarySearchTree &tree)
{
    std::streambuf *strbuf;
    std::string base = std::getenv("GUMPTION");
    std::ofstream ofstr(base + "/results/chapter7/" + fname);
    // 変更前の値を取得
    strbuf = std::cout.rdbuf(ofstr.rdbuf());
    // 標準出力へ出力（ファイルへ出力されます）
    tree.printTree();
    // 元に戻す
    std::cout.rdbuf(strbuf);
}

int main()
{
    BinarySearchTree t;
    watchTree("tree0.json", t);
    t.insert(Dict(10, "e"));
    t.insert(Dict(8, "g"));
    t.insert(Dict(2, "a"));
    t.insert(Dict(3, "b"));
    t.insert(Dict(4, "c"));
    t.insert(Dict(5, "d"));
    watchTree("tree1.json", t);
    t.remove(8);
    watchTree("tree2.json", t);
    t.remove(10);
    watchTree("tree3.json", t);
    t.remove(3);
    watchTree("tree4.json", t);
    t.remove(5);
    watchTree("tree5.json", t);
    t.remove(2);
    watchTree("tree6.json", t);
    t.remove(4);
    watchTree("tree7.json", t);
}
