#ifndef TREE_HPP
#define TREE_HPP

#include <stack>
#include <queue>

#include "Node.hpp"
using namespace std;

namespace ariel
{
    template <typename T, size_t k = 2>
    class Tree
    {
    private:
        Node<T, k> *root;
        size_t height;

    public:
        Tree(Node<T, k> *root = nullptr) : root(root), height(0) {}

        ~Tree()
        {
            // Implementing the destructor to clean up memory
            if (root != nullptr)
            {
                delete_tree(root);
            }
        }

        // Function to recursively delete the tree nodes
        void delete_tree(Node<T, k> *node)
        {
            if (node != nullptr)
            {
                for (size_t i = 0; i < node->getNumOfChildren(); ++i)
                {
                    delete_tree(node->children[i]);
                }
                delete node;
            }
        }

        void add_root(Node<T, k> *node)
        {
            if (root == nullptr)

            {
                if (node->getParent() == nullptr)
                {
                    root = node;
                    cout << "Root add seccesfuli" << endl;
                }
                else
                {
                    cout << "This node have parens, try to root him" << endl;
                    add_root(node->getParent());
                }
            }
            else
            {
                cout << "Root already exists" << endl;
            }
        }

        void add_sub_node(Node<T, k> *parent, Node<T, k> *child)
        {
            if (parent != nullptr)
            {
                parent->addChild(child);
            }
            else
            {
                cout << "Parent is nullptr." << endl;
            }
        }

        Node<T, k> *get_root() const
        {
            return root;
        }

        void print_tree() const
        {
            if (root != nullptr)
            {
                std::cout << "Printing Tree:" << std::endl;
                root->print_node();
            }
            else
            {
                std::cout << "Tree is empty." << std::endl;
            }
        }

        class BFSIterator
        {
        private:
            queue<Node<T, k> *> bfsQueue;

        public:
            BFSIterator(Node<T, k> *root)
            {
                if (root != nullptr)
                {
                    bfsQueue.push(root);
                }
            }

            bool hasNext() const
            {
                return !bfsQueue.empty();
            }

            Node<T, k> *next()
            {
                if (!hasNext())
                {
                    return nullptr;
                }

                Node<T, k> *current = bfsQueue.front();
                bfsQueue.pop();

                for (size_t i = 0; i < current->getNumOfChildren(); i++)
                {
                    if (current->children[i] != nullptr)
                    {
                        bfsQueue.push(current->children[i]);
                    }
                }
                return current;
            }
        }; // class BFS iterator

        class DFSIterator
        {
        private:
            stack<Node<T, k> *> dfsStack;

        public:
            DFSIterator(Node<T, k> *root)
            {
                if (root != nullptr)
                {
                    dfsStack.push(root);
                }
            }

            bool hasNext() const
            {
                return !dfsStack.empty();
            }

            Node<T, k> *next()
            {
                if (!hasNext())
                {
                    return nullptr;
                }

                Node<T, k> *current = dfsStack.top();
                dfsStack.pop();

                for (int i = current->getNumOfChildren() - 1; i >= 0; i--)
                {
                    if (current->children[i] != nullptr)
                    {
                        dfsStack.push(current->children[i]);
                    }
                }
                return current;
            }
        }; // class DFS iterator

        class PostOrderIterator
        {
        private:
            stack<Node<T, 2> *> s1, s2;

        public:
            PostOrderIterator(Node<T, 2> *root)
            {
                if (root != nullptr)
                {
                    s1.push(root);
                    while (!s1.empty())
                    {
                        Node<T, 2> *node = s1.top();
                        s1.pop();
                        s2.push(node);
                        if (node->children[0] != nullptr)
                            s1.push(node->children[0]);
                        if (node->children[1] != nullptr)
                            s1.push(node->children[1]);
                    }
                }
            }

            bool hasNext() const
            {
                return !s2.empty();
            }

            Node<T, 2> *next()
            {
                if (!hasNext())
                    return nullptr;
                Node<T, 2> *node = s2.top();
                s2.pop();
                return node;
            }
        }; // class PostOrderIterator

        class PreOrderIterator
        {
        private:
            stack<Node<T, 2> *> s;

        public:
            PreOrderIterator(Node<T, 2> *root)
            {
                if (root != nullptr)
                    s.push(root);
            }

            bool hasNext() const
            {
                return !s.empty();
            }

            Node<T, 2> *next()
            {
                if (!hasNext())
                    return nullptr;
                Node<T, 2> *node = s.top();
                s.pop();
                if (node->children[1] != nullptr)
                    s.push(node->children[1]);
                if (node->children[0] != nullptr)
                    s.push(node->children[0]);
                return node;
            }
        }; // class PreOrderIterator

        class InOrderIterator
        {
        private:
            stack<Node<T, 2> *> s;
            Node<T, 2> *current;

        public:
            InOrderIterator(Node<T, 2> *root) : current(root) {}

            bool hasNext() const
            {
                return !s.empty() || current != nullptr;
            }

            Node<T, 2> *next()
            {
                while (current != nullptr)
                {
                    s.push(current);
                    current = current->children[0];
                }

                if (s.empty())
                    return nullptr;

                Node<T, 2> *node = s.top();
                s.pop();
                current = node->children[1];
                return node;
            }
        }; // class InOrderIterator

        BFSIterator bfs_begin()
        {
            return BFSIterator(root);
        }

        DFSIterator dfs_begin()
        {
            return DFSIterator(root);
        }

        PostOrderIterator post_order_begin()
        {
            if constexpr (k != 2)
            {
                throw std::runtime_error("Post-order traversal is only supported for binary trees (k=2)");
            }
            return PostOrderIterator(root);
        }

        PreOrderIterator pre_order_begin()
        {
            if constexpr (k != 2)
            {
                throw std::runtime_error("Pre-order traversal is only supported for binary trees (k=2)");
            }
            return PreOrderIterator(root);
        }

        InOrderIterator in_order_begin()
        {
            if constexpr (k != 2)
            {
                throw std::runtime_error("In-order traversal is only supported for binary trees (k=2)");
            }
            return InOrderIterator(root);
        }

    }; // class Tree
} // namespace ariel

#endif // TREE_HPP
