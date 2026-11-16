
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
/*
## **1. Theory**

A **Binary Search Tree (BST)** is a non-linear data structure in which each node has at most two children.

- Left child contains a smaller value.
- Right child contains a greater value.
- It supports insertion, searching and traversal operations.

## **2. Algorithm**

**Insertion:**

1. Start from the root node.
2. If the root is NULL, create a new node.
3. If the value is smaller than the root, insert it into the left subtree.
4. If the value is greater than the root, insert it into the right subtree.
5. Return the root node.

**Inorder Traversal:**

1. Traverse the left subtree.
2. Display the root node.
3. Traverse the right subtree.

**Preorder Traversal:**

1. Display the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

**Postorder Traversal:**

1. Traverse the left subtree.
2. Traverse the right subtree.
3. Display the root node.

**Searching:**

1. Start from the root.
2. If the value matches, display "Element found".
3. If the value is smaller, search the left subtree.
4. Otherwise, search the right subtree.
5. If the node is NULL, display "Element not found".

## **3. Example**

Insert the following values into the BST:

`50, 30, 70, 20, 40`

**BST Structure:**

```
          50
         /  \
       30    70
      /  \
    20    40
```

**Output:**

```
Inorder:   20 30 40 50 70
Preorder:  50 30 20 40 70
Postorder: 20 40 30 70 50
```

Search element: `40`

Output: `Element found`

## **4. Conclusion**

Thus, we have successfully implemented a Binary Search Tree using C++ and performed insertion, searching, inorder, preorder and postorder traversal operations.
*/