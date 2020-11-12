#include <expectation.h>
#include "binary_search_tree.h"

void testBinarySearchLeafSimple()
{
    BinarySearchLeaf l;
}

void testBinarySearchTreeSimple()
{
    BinarySearchTree t;
}

void testBinarySearchTreeInsertSimple()
{
    BinarySearchTree t;
    t.insert(Dict(1, "a"));
    expect(t.locate(0).value).to_be("a");
    expect(t.locate(1).value).to_be("a");
    expect(t.locate(2).value).to_be("");
    expect(t.height()).to_be(1);
}

void testBinarySearchTreeInsertNormal1()
{
    BinarySearchTree t;
    t.insert(Dict(1, "a"));
    t.insert(Dict(2, "b"));
    t.insert(Dict(5, "e"));
    t.insert(Dict(4, "d"));
    t.insert(Dict(3, "c"));
    t.insert(Dict(6, "f"));
    t.Print();
    expect(t.locate(0).value).to_be("a");
    expect(t.locate(1).value).to_be("a");
    expect(t.locate(2).value).to_be("b");
    expect(t.locate(3).value).to_be("c");
    expect(t.locate(4).value).to_be("d");
    expect(t.locate(5).value).to_be("e");
    expect(t.locate(6).value).to_be("f");

    expect(t.locate(7).value).to_be("");
    expect(t.height()).to_be(5);
}

void testBinarySearchTreeInsertNormal2()
{
    BinarySearchTree t;
    t.insert(Dict(10, "e"));
    t.insert(Dict(2, "a"));
    t.insert(Dict(3, "b"));
    t.insert(Dict(4, "c"));
    t.insert(Dict(5, "d"));
    t.Print();
    expect(t.locate(10).value).to_be("e");
    expect(t.locate(2).value).to_be("a");
    expect(t.locate(3).value).to_be("b");
    expect(t.locate(4).value).to_be("c");
    expect(t.locate(5).value).to_be("d");

    expect(t.height()).to_be(5);
}

void testPrint()
{
    BinarySearchTree t;
    t.insert(Dict(1, "a"));
    t.Print();
}

int main()
{
    executeTestSuite("葉のテストSimple", testBinarySearchLeafSimple);
    executeTestSuite("二分木のテストSimple", testBinarySearchTreeSimple);
    executeTestSuite("二分木のプリント", testPrint);
    executeTestSuite("二分木のInsertテストSimple", testBinarySearchTreeInsertSimple);
    executeTestSuite("二分木のInsertテストNormal1", testBinarySearchTreeInsertNormal1);
    executeTestSuite("二分木のInsertテストNormal2", testBinarySearchTreeInsertNormal2);

    return 0;
}
