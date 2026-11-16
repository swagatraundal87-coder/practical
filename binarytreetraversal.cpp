
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createTree()
{
    int value;

    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* newNode = new Node;
    newNode->data = value;

    cout << "Enter left child of " << value << endl;
    newNode->left = createTree();

    cout << "Enter right child of " << value << endl;
    newNode->right = createTree();

    return newNode;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* root = NULL;

    cout << "Create Binary Tree\n";
    root = createTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}
