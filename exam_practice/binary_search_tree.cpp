#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *right;
    Node *left;
};

Node *newNode(int value)
{
    Node *node = new Node();
    node->val = value;
    node->right = nullptr;
    node->left = nullptr;
    return node;
}

Node *insertNode(Node *node, int value)
{
    if (node == nullptr)
    {
        return newNode(value);
    }

    if (value < node->val)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->val)
    {
        node->right = insertNode(node->right, value);
    }

    return node;
}

Node *deleteNode(Node *node, int value)
{
    if (node == nullptr)
        return node;

    if (value < node->val)
    {
        node->left = deleteNode(node->left, value);
        return node;
    }
    else if (value > node->val)
    {
        node->right = deleteNode(node->right, value);
        return node;
    }

    if (node->left == nullptr)
    {
        Node *temp = node->right;
        delete node;
        return temp;
    }
    else if (node->right == nullptr)
    {
        Node *temp = node->left;
        delete node;
        return temp;
    }

    Node *succParent = node;
    Node *succ = node->right;

    while (succ->left != nullptr)
    {
        succParent = succ;
        succ = succ->left;
    }

    node->val = succ->val;

    if (succParent->left == succ)
    {
        succParent->left = succ->right;
    }
    else
    {
        succParent->right = succ->right;
    }

    delete succ;

    return node;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        root = insertNode(root, x);
    }

    inorder(root);
    cout << endl;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        root = deleteNode(root, x);

        cout << "After deletion of node " << x << ": ";
        inorder(root);
        cout << endl;

        root = insertNode(root, x);
    }

    return 0;
}
