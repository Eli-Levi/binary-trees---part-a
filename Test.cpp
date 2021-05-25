#include "doctest.h"
#include <iostream>
#include <string>
#include "BinaryTree.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("valid empty case")
{
    BinaryTree<int> tree;
    CHECK_EQ(tree.get_root(), nullptr);
}

TEST_CASE("adding root properly")
{
    BinaryTree<int> tree;
    tree.add_root(5);
    CHECK_EQ(tree.get_root()->value, 5);

    BinaryTree<string> stree;
    stree.add_root("hello");
    CHECK_EQ(stree.get_root()->value, "hello");
}

TEST_CASE("replacing current root")
{
    BinaryTree<int> tree;
    tree.add_root(5);
    tree.add_root(20);
    CHECK_EQ(tree.get_root()->value, 20);

    BinaryTree<string> stree;
    stree.add_root("hello");
    stree.add_root("world");
    CHECK_EQ(stree.get_root()->value, "world");
}

TEST_CASE("adding left child")
{
    BinaryTree<int> tree;
    tree.add_root(5);
    tree.add_left(tree.get_root()->value, 20);
    CHECK_EQ(tree.get_left(tree.get_root())->value, 20);

    BinaryTree<string> stree;
    stree.add_root("hello");
    stree.add_left(stree.get_root()->value, "world");
    CHECK_EQ(stree.get_left(stree.get_root())->value, "world");
}

TEST_CASE("replacing left child")
{
    BinaryTree<int> tree;
    tree.add_root(5);
    tree.add_left(tree.get_root()->value, 20);
    tree.add_left(tree.get_root()->value, 80);
    CHECK_EQ(tree.get_left(tree.get_root())->value, 80);

    BinaryTree<string> stree;
    stree.add_root("hello");
    stree.add_left(stree.get_root()->value, "world");
    stree.add_left(stree.get_root()->value, "there");
    CHECK_EQ(stree.get_left(stree.get_root())->value, "there");
}

TEST_CASE("adding right child")
{
    BinaryTree<int> tree;
    tree.add_root(5);
    tree.add_right(tree.get_root()->value, 99);
    CHECK_EQ(tree.get_right(tree.get_root())->value, 99);

    BinaryTree<string> stree;
    stree.add_root("hello");
    stree.add_right(stree.get_root()->value, "you");
    CHECK_EQ(stree.get_right(stree.get_root())->value, "you");
}

TEST_CASE("invalid input: adding right child to non existing root")
{
    BinaryTree<int> tree;
    CHECK_THROWS(tree.add_right(tree.get_root()->value, 99));

    BinaryTree<string> stree;
    CHECK_THROWS(stree.add_right(stree.get_root()->value , "you"));
}

TEST_CASE("invalid input: adding left child to non existing root")
{
    BinaryTree<int> tree;
    CHECK_THROWS(tree.add_left(tree.get_root()->value , 42));

    BinaryTree<string> stree;
    CHECK_THROWS(stree.add_left(stree.get_root()->value , "you"));
}

/*TEST_CASE("invalid input: adding right child to non existing node")
{
    BinaryTree<int> tree;
    tree.add_root(-7);
    tree.add_right(tree.get_root()->value, 99);
    CHECK_THROWS(87, 420);

    BinaryTree<string> stree;
    stree.add_root("yo");
    stree.add_right(stree.get_root().value,"sup");
    CHECK_THROWS(stree.add_right(stree.get_root().get_right().get_right(),"you") );
}

TEST_CASE("invalid input: adding left child to non existing node")
{
    BinaryTree<int> tree;
    CHECK_THROWS(tree.add_left(tree.get_root()->value , 42);

    BinaryTree<string> stree;
    CHECK_THROWS(stree.add_left(stree.get_root()->value , "you");
}*/
