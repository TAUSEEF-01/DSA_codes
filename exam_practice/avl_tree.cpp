#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *right;
    Node *left;
    int height;
};

Node *newNode(int value)
{
    Node *node = new Node();
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;

    return node;
}

int height(Node *node)
{
    if (!node)
        return 0;

    return node->height;
}

Node *rotateRight(Node *node)
{
    Node *node_left = node->left;
    Node *node_left_right = node_left->right;

    node->left = node_left_right;
    node_left->right = node;

    node->height = max(height(node->right), height(node->left)) + 1;
    node_left->height = max(height(node_left->left), height(node_left->right)) + 1;

    return node_left;
}

Node *rotateLeft(Node *node)
{
    Node *node_right = node->right;
    Node *node_right_left = node_right->left;

    node->right = node_right_left;
    node_right->left = node;

    node->height = max(height(node->right), height(node->left)) + 1;
    node_right->height = max(height(node_right->left), height(node_right->right)) + 1;

    return node_right;
}

int balanceFactor(Node *node)
{
    if (!node)
        return 0;

    return height(node->left) - height(node->right);
}

Node *insertNode(Node *node, int value)
{
    if (!node)
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
    else
    {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = balanceFactor(node);

    // LL case
    if (balance > 1 && value < node->left->val)
    {
        return rotateRight(node);
    }

    // RR case
    if (balance < -1 && value > node->right->val)
    {
        return rotateLeft(node);
    }

    // LR case
    if (balance > 1 && value > node->left->val)
    {
        node->left = rotateLeft(node->left); // be careful ---> node->left is used twice not node
        return rotateRight(node);            // be careful ---> only node is used
    }

    // RL case
    if (balance < -1 && value < node->right->val)
    {
        node->right = rotateRight(node->right); // be careful ---> node->right is used twice not node
        return rotateLeft(node);                // be careful ---> only node is used
    }

    return node;
}

bool find_it(Node *node, int val)
{
    bool b1 = false, b2 = false;

    if (node == NULL)
    {
        return false;
    }
    if (node->val == val)
    {
        return true;
    }

    if (val < node->val)
        b1 = find_it(node->left, val);
    else if (val > node->val)
        b2 = find_it(node->right, val);

    return b1 | b2;
}


void inorder(Node *node)
{
    if (!node)
        return;

    inorder(node->left);
    // cout << node->val << ' ' << balanceFactor(node) << endl;
    cout << node->val << ' ' << node->height << endl;
    inorder(node->right);
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
        // cout << root->val << endl;
    }

    inorder(root);


    // int m;
    // cin >> m;

    // for(int i = 0; i < m; i++)
    // {
    //     int q;
    //     cin >> q;

    //     if(find_it(root, q))
    //     cout << 1 << endl;
    //     else
    //     cout << 0 << endl;
    // }

    return 0;
}
