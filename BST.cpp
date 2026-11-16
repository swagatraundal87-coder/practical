
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
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

void search(Node* root, int key)
{
    if (root == NULL)
    {
        cout << "Element not found";
        return;
    }

    if (root->data == key)
        cout << "Element found";
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int main()
{
    Node* root = NULL;
    int choice, value;

    do
    {
        cout << "\n\n1. Insert";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Search";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                search(root, value);
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 6);

    return 0;
}
