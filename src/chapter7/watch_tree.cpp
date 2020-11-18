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
    t.insert(Dict(1, "a"));
    t.insert(Dict(2, "b"));
    t.insert(Dict(5, "e"));
    t.insert(Dict(4, "d"));
    t.insert(Dict(3, "c"));
    t.insert(Dict(6, "f"));
    watchTree("tree.json", t);
}
