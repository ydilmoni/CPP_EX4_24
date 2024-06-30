#include <iostream>
#include "node.hpp"

using namespace ariel;
int main()
{
    Node<int> root(1); // Uses default N = 2
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);

    root.addChild(&child1);
    root.addChild(&child2);

    std::cout << "Root value: " << root.getValue() << std::endl;
    std::cout << "Root children count: " << root.getNumOfChild() << std::endl;

    return 0;
}