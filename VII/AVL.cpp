#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

class AVLTree
{
public:
    Node *root;
    AVLTree()
    {
        root = NULL;
    }

    int height(Node *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    Node *newNode(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return node;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node *n)
    {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
            return (newNode(data));

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left),
                               height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main()
{
    AVLTree tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    cout << "Inorder traversal of the constructed AVL tree is \n";
    tree.inorder(tree.root);
    return 0;
}
