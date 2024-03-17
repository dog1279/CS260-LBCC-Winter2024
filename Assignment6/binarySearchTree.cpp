#include <iostream>

// Define the structure of a node in the binary search tree
struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    // Helper function to add a value to the tree
    Node *addRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }
        if (value <= current->value)
        {
            current->left = addRecursive(current->left, value);
        }
        else
        {
            current->right = addRecursive(current->right, value);
        }
        return current;
    }

    // Helper function to find the minimum value node in a subtree
    Node *findMinNode(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // Helper function to remove a value from the tree
    Node *removeRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return nullptr;
        }
        if (value < current->value)
        {
            current->left = removeRecursive(current->left, value);
        }
        else if (value > current->value)
        {
            current->right = removeRecursive(current->right, value);
        }
        else
        {
            // Node to delete found
            if (current->left == nullptr)
            {
                Node *temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr)
            {
                Node *temp = current->left;
                delete current;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = findMinNode(current->right);
            current->value = temp->value;
            current->right = removeRecursive(current->right, temp->value);
        }
        return current;
    }

    // Helper function for in-order traversal
    void inOrderRecursive(Node *node)
    {
        if (node != nullptr)
        {
            inOrderRecursive(node->left);
            std::cout << node->value << " ";
            inOrderRecursive(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    // Public function to add a value to the tree
    void add(int value)
    {
        root = addRecursive(root, value);
    }

    // Public function to remove a value from the tree
    void remove(int value)
    {
        root = removeRecursive(root, value);
    }

    // Public function to perform in-order traversal of the tree
    void inOrderTraversal()
    {
        inOrderRecursive(root);
        std::cout << std::endl;
    }
};

// test time!!
int main()
{
    // Test add function
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(1);
    tree.add(4);
    tree.add(6);
    tree.add(9);

    // Test in-order traversal
    std::cout << "In-order traversal: ";
    tree.inOrderTraversal(); // Output should be: 1 3 4 5 6 7 9

    // Test remove function
    tree.remove(3); // Removing a node with one child
    tree.remove(7); // Removing a node with two children

    // Test in-order traversal after removal
    std::cout << "In-order traversal after removal: ";
    tree.inOrderTraversal(); // Output should be: 1 4 5 6 9

    return 0;
}
