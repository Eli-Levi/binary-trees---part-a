#include "doctest.h"
#include <iostream>
#include <string>
#include "BinaryTree.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("valid empty case")
{
    BinaryTree<int> tree;
    CHECK(tree.get_root() == nullptr);
}

TEST_CASE("adding root properly")
{
    cout << "bla\n";
    BinaryTree<int> tree;
    cout << "bla bla\n";
    CHECK_NOTHROW(tree.add_root(5));
    cout << "bla bla bla\n";

    CHECK(tree.get_root()->value == 5);
    cout << "bla bla bla bla\n";

    BinaryTree<string> stree;
    cout << "bla bla bla bla bla\n";

    stree.add_root("hello");
    cout << "FUCK\n";
}

TEST_CASE("replacing current root")
{
    BinaryTree<int> tree;
    cout << "ONE FELL DOWN\n";

    CHECK_NOTHROW(tree.add_root(5));
    cout << "PASS IT AROUND\n";

    CHECK_NOTHROW(tree.add_root(20));
    CHECK(tree.get_root()->value == 20);
}

TEST_CASE("adding left child")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(5));
    CHECK_NOTHROW(tree.add_left(tree.get_root()->value, 20));
    CHECK(tree.get_left(tree.get_root())->value == 20);
}

TEST_CASE("replacing left child")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(5));
    CHECK_NOTHROW(tree.add_left(tree.get_root()->value, 20));
    CHECK_NOTHROW(tree.add_left(tree.get_root()->value, 80));
    CHECK(tree.get_left(tree.get_root())->value == 80);
}

TEST_CASE("adding right child")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(5));
    CHECK_NOTHROW(tree.add_right(tree.get_root()->value, 99));
    CHECK(tree.get_right(tree.get_root())->value == 99);
}

TEST_CASE("invalid input: adding right child to non existing root")
{
    BinaryTree<int> tree;
    CHECK_THROWS(tree.add_right(tree.get_root()->value, 99));
}
TEST_CASE("invalid input: adding left child to non existing root")
{
    BinaryTree<int> tree;
    CHECK_THROWS(tree.add_left(tree.get_root()->value, 42));
}

TEST_CASE("invalid input: adding right child to non existing node")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(-7));
    CHECK_NOTHROW(tree.add_right(tree.get_root()->value, 99));
    CHECK_THROWS(tree.add_right(110, 420));
}

TEST_CASE("invalid input: adding left child to non existing node")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(-7));
    CHECK_NOTHROW(tree.add_right(tree.get_root()->value, 99));
    CHECK_THROWS(tree.add_left(3584654, 42));
}
