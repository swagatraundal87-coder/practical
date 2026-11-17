
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
/*
## **1. Theory**

A **Binary Tree** is a non-linear data structure in which each node can have at most two children: a left child and a right child.

There are three main types of tree traversal:

- **Inorder:** Left → Root → Right
- **Preorder:** Root → Left → Right
- **Postorder:** Left → Right → Root

In this program, `-1` is used to indicate that a node does not exist.

## **2. Algorithm**

1. Start.
2. Create a binary tree using nodes.
3. Enter the value of each node.
4. Enter `-1` if a node does not exist.
5. For Inorder Traversal:
   - Traverse the left subtree.
   - Display the root node.
   - Traverse the right subtree.
6. For Preorder Traversal:
   - Display the root node.
   - Traverse the left subtree.
   - Traverse the right subtree.
7. For Postorder Traversal:
   - Traverse the left subtree.
   - Traverse the right subtree.
   - Display the root node.
8. Display all traversal results.
9. Stop.

## **3. Example**

**Input:**

```
1
2
4
-1
-1
5
-1
-1
3
-1
-1
```

**Binary Tree Structure:**

```
       1
      / \
     2   3
    / \
   4   5
```

**Output:**

```
Inorder Traversal: 4 2 5 1 3

Preorder Traversal: 1 2 4 5 3

Postorder Traversal: 4 5 2 3 1
```

## **4. Conclusion**

Thus, we have successfully implemented a Binary Tree in C++ and performed Inorder, Preorder and Postorder traversal operations.
*/