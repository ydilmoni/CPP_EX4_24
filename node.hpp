#ifndef NODE_HPP
#define NODE_HPP

#include <array>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    template <typename T, size_t n = 2>
    class Node
    {
    private:
        size_t child_count;
        T value;
        Node *parent;
        array<Node *, n> children;

    public:
        Node(const T value) : value(value), child_count(0), parent(nullptr)
        {
            children.fill(nullptr);
        }

        void addChild(Node *newChild)
        {
            if (child_count < n)
            {
                children[child_count++] = newChild;
                newChild->parent = this;
                cout << "Child successfully added" << endl;
            }
            else
            {
                cout << "This node have the maximum amount of child" << endl;
            }
        }

        void removeChild(Node *chiltToDelete)
        {
            bool found = false;
            for (size_t i = 0; i < child_count; i++)
            {
                if (children[i] == chiltToDelete)
                {
                    found = true;
                }
                for (size_t j = i; j < child_count - 1; j++)
                {
                    children[j] = children[j + 1];
                }
                children[child_count - 1] = nullptr;
                --child_count;
                chiltToDelete->parent = nullptr;
                cout << "Child successfully removed" << endl;
                break;
            }
            if (!found)
            {
                cout << "This node doesn't have this child" << endl;
            }
        }

        const T &getValue() const
        {
            return value;
        }

        std::size_t getNumOfChild() const
        {
            return child_count;
        }
    };

} // namespace ariel

#endif // NODE_HPP
