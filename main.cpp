#include <iostream>
// #include "Complex.hpp"
#include "Tree.hpp"
#include "Node.hpp"

using namespace ariel;
using namespace std;

int main()
{
    // Create 15 int nodes for binary tree
    Node<int> *root = new Node<int>(1);
    Node<int> *node1 = new Node<int>(2);
    Node<int> *node2 = new Node<int>(3);
    Node<int> *node3 = new Node<int>(4);
    Node<int> *node4 = new Node<int>(5);
    Node<int> *node5 = new Node<int>(6);
    Node<int> *node6 = new Node<int>(7);
    Node<int> *node7 = new Node<int>(8);
    Node<int> *node8 = new Node<int>(9);
    Node<int> *node9 = new Node<int>(10);
    Node<int> *node10 = new Node<int>(11);
    Node<int> *node11 = new Node<int>(12);
    Node<int> *node12 = new Node<int>(13);
    Node<int> *node13 = new Node<int>(14);
    Node<int> *node14 = new Node<int>(15);

    // Connect nodes

    Tree<int> tree(root);
    tree.add_sub_node(root, node1);
    tree.add_sub_node(root, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node2, node6);
    tree.add_sub_node(node3, node7);
    tree.add_sub_node(node3, node8);
    tree.add_sub_node(node4, node9);
    tree.add_sub_node(node4, node10);
    tree.add_sub_node(node5, node11);
    tree.add_sub_node(node5, node12);
    tree.add_sub_node(node6, node13);
    tree.add_sub_node(node6, node14);

    // Create a Tree<int, 3> object and try to put node8 as root.

    // BFS traversal
    Tree<int>::BFSIterator bfs = tree.bfs_begin();
    while (bfs.hasNext())
    {
        Node<int> *node = bfs.next();
        cout << node->getValue() << endl;
    }

    // tree.print_tree();

    Tree<int>::DFSIterator dfs = tree.dfs_begin();
    while (dfs.hasNext())
    {
        Node<int> *node = dfs.next();
        cout << node->getValue() << endl;
    }

    // Post-order traversal
    Tree<int, 2>::PostOrderIterator post_it = tree.post_order_begin();
    while (post_it.hasNext())
    {
        Node<int, 2> *node = post_it.next();
        cout << node->getValue() << " ";
    }
    cout << endl;

    // Pre-order traversal
    Tree<int, 2>::PreOrderIterator pre_it = tree.pre_order_begin();
    while (pre_it.hasNext())
    {
        Node<int, 2> *node = pre_it.next();
        cout << node->getValue() << " ";
    }
    cout << endl;

    // In-order traversal
    Tree<int, 2>::InOrderIterator in_it = tree.in_order_begin();
    while (in_it.hasNext())
    {
        Node<int, 2> *node = in_it.next();
        cout << node->getValue() << " ";
    }
    cout << endl;

    return 0;
}