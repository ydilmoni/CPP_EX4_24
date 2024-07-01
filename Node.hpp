#ifndef NODE_HPP
#define NODE_HPP

#include <array>
#include <stdexcept>
#include <iostream>
#include <string>
#include <array>

using namespace std;

namespace ariel
{
    template <typename T, size_t n = 2>
    class Node
    {
    private:
        size_t height;
        T value;
        Node *parent;

    public:
        size_t child_count;
        array<Node<T, n> *, n> children;
        Node(T value) : value(value), child_count(0), parent(nullptr), height(0)
        {
            children.fill(nullptr);
        }

        Node(const Node &other)
        {
            value = other.getValue();
            child_count = other.child_count;
            parent = other.getParent();

            height = other.getHeight();
            children.fill(nullptr);
            for (size_t i = 0; i < child_count; i++)
            {
                children[i] = other.children[i];
            }
        }

        void addChild(Node<T, n> *newChild)
        {
            if (this->getNumOfChildren() < n)
            {
                children[child_count++] = newChild;
                newChild->setParent(this);
                newChild->setHeight(this->getHeight() + 1);
                cout << "Child successfully added" << endl;
            }

            else
            {
                cout << "This node have the maximum amount of child" << endl;
            }
        }

        void setParent(Node *parent)
        {
            this->parent = parent;
        }

        void removeChild(Node *chiltToDelete)
        {
            bool found = false;
            for (size_t i = 0; i < child_count; i++)
            {
                if (children[i] == chiltToDelete)
                {
                    found = true;
                    for (size_t j = i; j < child_count - 1; j++)
                    {
                        children[j] = children[j + 1];
                    }
                    children[child_count - 1] = nullptr;
                    --child_count;
                    chiltToDelete->setParent(nullptr);
                    chiltToDelete->setHeight(0);
                    cout << "Child successfully removed" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "This node doesn't have this child" << endl;
            }
        }

        void print_node(int level = 0) const
        {
            // Print the current node's value at the specified indentation level
            std::cout << std::string(level, '-') << "> Node Value: " << value << std::endl;

            // Recursively print each child node
            for (size_t i = 0; i < child_count; ++i)
            {
                if (children[i] != nullptr)
                {
                    children[i]->print_node(level + 1);
                }
            }
        }

            const T &getValue() const
            {
                return value;
            }

            size_t getNumOfChildren() const
            {
                return child_count;
            }
            size_t getHeight()
            {
                return height;
            }
            void setHeight(size_t h)
            {
                height = h;
            }
            Node *getParent()
            {
                return parent;
            }
        };

    } // namespace ariel

#endif // NODE_HPP
