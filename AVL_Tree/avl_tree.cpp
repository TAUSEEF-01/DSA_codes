#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    int height;
};

int height(Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

Node *newNode(int value)
{
    Node *node = new Node();
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *right_Rotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *left_Rotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int get_balance_factor(Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

Node *insert(Node *node, int value)
{
    if (node == NULL)
        return (newNode(value));

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance_factor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return right_Rotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return left_Rotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value)
    {
        node->left = left_Rotate(node->left);
        return right_Rotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value)
    {
        node->right = right_Rotate(node->right);
        return left_Rotate(node);
    }

    return node;
}

Node *findBSTMin(Node *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

Node *deleteBSTMin(Node *node)
{
    if (node == nullptr)
        return nullptr;

    if (node->left == nullptr)
    {
        Node *temp = node->right;
        free(node);
        return temp;
    }

    node->left = deleteBSTMin(node->left);
    return node;
}

Node *deleteNode(Node *node, int number)
{
    if (node == nullptr)
        return nullptr;

    if (number < node->value)
    {
        node->left = deleteNode(node->left, number);
    }
    else if (number > node->value)
    {
        node->right = deleteNode(node->right, number);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            free(node);
            return nullptr;
        }
        else if (node->left == nullptr)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }

        Node *temp = findBSTMin(node->right);
        node->value = temp->value;
        node->right = deleteBSTMin(node->right);
    }

    return node;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    preOrder(root);
    cout << endl;

    deleteNode(root, 10);

    preOrder(root);

    return 0;
}
