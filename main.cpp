#include <iostream>
// #include "Complex.hpp"
#include "Tree.hpp"
#include "Node.hpp"

using namespace ariel;
using namespace std;

int main()
{
    // Create 12 int nodes
    Node<int, 3> *node1 = new Node<int, 3>(1);
    Node<int, 3> *node2 = new Node<int, 3>(2);
    Node<int, 3> *node3 = new Node<int, 3>(3);
    Node<int, 3> *node4 = new Node<int, 3>(4);
    Node<int, 3> *node5 = new Node<int, 3>(5);
    Node<int, 3> *node6 = new Node<int, 3>(6);
    Node<int, 3> *node7 = new Node<int, 3>(7);
    Node<int, 3> *node8 = new Node<int, 3>(8);
    Node<int, 3> *node9 = new Node<int, 3>(9);
    Node<int, 3> *node10 = new Node<int, 3>(10);

    node3->addChild(node2);
    node3->addChild(node4);
    node3->addChild(node5);
    node2->addChild(node1);
    node2->addChild(node6);
    node4->addChild(node7);
    node4->addChild(node8);
    node5->addChild(node9);
    node9->addChild(node10);

    // Create a Tree<int, 3> object and try to put node8 as root.
    Tree<int, 3> tree;
    tree.add_root(node10);

    // BFS traversal
    Tree<int, 3>::BFSIterator bfs = tree.bfs_begin();
    while (bfs.hasNext())
    {
        Node<int, 3> *node = bfs.next();
        cout << node->getValue() << endl;
    }

    tree.print_tree();

    Tree<int, 3>::DFSIterator dfs = tree.dfs_begin();
    while (dfs.hasNext())
    {
        Node<int, 3>* node = dfs.next();
        cout << node->getValue() << endl;
    }

    return 0;
}