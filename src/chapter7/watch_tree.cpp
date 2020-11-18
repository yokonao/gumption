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
    t.insert(Dict(10, "e"));
    t.insert(Dict(8, "g"));
    t.insert(Dict(2, "a"));
    t.insert(Dict(3, "b"));
    t.insert(Dict(4, "c"));
    t.insert(Dict(5, "d"));
    watchTree("tree1.json", t);
    t.remove(8);
    watchTree("tree2.json", t);
}
