#include <QApplication>
#include "MainWindow.hpp"
#include "Tree.hpp"
#include "Node.hpp"
#include "Complex.hpp"

using namespace ariel;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Node<int> *root = new Node<int>(10000);
    // Node<int> *node0 = new Node<int>(0);
    // Node<int> *node1 = new Node<int>(1);
    // Node<int> *node2 = new Node<int>(2);
    // Node<int> *node3 = new Node<int>(3);
    // Node<int> *node4 = new Node<int>(4);
    // Node<int> *node5 = new Node<int>(5);
    // Tree<int> tree(node5);
    // Node<int> *node6 = new Node<int>(6);
    // Node<int> *node7 = new Node<int>(7);
    // Node<int> *node8 = new Node<int>(8);
    // Node<int> *node9 = new Node<int>(9);
    // Node<int> *node10 = new Node<int>(10);
    // Node<int> *node11 = new Node<int>(11);
    // Node<int> *node12 = new Node<int>(12);
    // Node<int> *node13 = new Node<int>(13);
    // Node<int> *node14 = new Node<int>(14);
    // Node<int> *node15 = new Node<int>(15);
    // Node<int> *node16 = new Node<int>(16);

    // // Connect nodes
    // tree.add_sub_node(root, node0);
    // tree.add_sub_node(node0, node1);
    // tree.add_sub_node(node0, node2);
    // tree.add_sub_node(node1, node3);
    // tree.add_sub_node(node1, node4);
    // tree.add_sub_node(node2, node5);
    // tree.add_sub_node(node2, node6);
    // tree.add_sub_node(node3, node7);
    // tree.add_sub_node(node3, node8);
    // tree.add_sub_node(node4, node9);
    // tree.add_sub_node(node4, node10);
    // tree.add_sub_node(node5, node11);
    // tree.add_sub_node(node5, node12);
    // tree.add_sub_node(node6, node13);
    // tree.add_sub_node(node6, node14);

    // cout<<endl;

    // cout<<tree.getHeight()<<endl;
    // tree.add_sub_node(node14, node15);
    // tree.add_sub_node(node15, node16);
    // cout<<tree.getHeight()<<endl;

    // Complex croot(1, 2);
    // Complex c0(2, 3);
    // Complex c1(2, 3);
    // Complex c2(3, 4);
    // Complex c3(4, 5);
    // Complex c4(5, 6);
    // Complex c5(6, 7);
    // Complex c6(7, 8);
    // Complex c7(8, 9);
    // Complex c8(9, 10);

    // // Create nodes
    // Node<Complex, 3> *root = new Node<Complex, 3>(croot);
    // Node<Complex, 3> *node0 = new Node<Complex, 3>(c0);
    // Node<Complex, 3> *node1 = new Node<Complex, 3>(c1);
    // Node<Complex, 3> *node2 = new Node<Complex, 3>(c2);
    // Node<Complex, 3> *node3 = new Node<Complex, 3>(c3);
    // Node<Complex, 3> *node4 = new Node<Complex, 3>(c4);
    // Node<Complex, 3> *node5 = new Node<Complex, 3>(c5);
    // Node<Complex, 3> *node6 = new Node<Complex, 3>(c6);
    // Node<Complex, 3> *node7 = new Node<Complex, 3>(c7);
    // Node<Complex, 3> *node8 = new Node<Complex, 3>(c8);


    // // Create tree and add nodes
    // Tree<Complex, 3> tree(root);
    // tree.add_root(root);
    // tree.add_sub_node(root, node0);
    // tree.add_sub_node(node0, node1);
    // tree.add_sub_node(node0, node2);
    // tree.add_sub_node(node0, node3);
    // tree.add_sub_node(node1, node4);
    // tree.add_sub_node(node2, node5);
    // tree.add_sub_node(node2, node6);
    // tree.add_sub_node(node3, node7);
    // tree.add_sub_node(node3, node8);
    // MainWindow<Complex, 3> mainWindow(nullptr, &tree); // Pass tree by reference
    // mainWindow.show();
    // return app.exec();

    // // BFS traversal
    // Tree<int>::BFSIterator bfs = tree.bfs_begin();
    // while (bfs.hasNext())
    // {
    //     Node<int> *node = bfs.next();
    //     cout << node->getValue() << endl;
    // }

    // // tree.print_tree();

    // Tree<int>::DFSIterator dfs = tree.dfs_begin();
    // while (dfs.hasNext())
    // {
    //     Node<int> *node = dfs.next();
    //     cout << node->getValue() << endl;
    // }

    // // Post-order traversal
    // Tree<int, 2>::PostOrderIterator post_it = tree.post_order_begin();
    // while (post_it.hasNext())
    // {
    //     Node<int, 2> *node = post_it.next();
    //     cout << node->getValue() << " ";
    // }
    // cout << endl;

    // // Pre-order traversal
    // Tree<int, 2>::PreOrderIterator pre_it = tree.pre_order_begin();
    // while (pre_it.hasNext())
    // {
    //     Node<int, 2> *node = pre_it.next();
    //     cout << node->getValue() << " ";
    // }
    // cout << endl;

    // // In-order traversal
    // Tree<int, 2>::InOrderIterator in_it = tree.in_order_begin();
    // while (in_it.hasNext())
    // {
    //     Node<int, 2> *node = in_it.next();
    //     cout << node->getValue() << " ";
    // }

}
