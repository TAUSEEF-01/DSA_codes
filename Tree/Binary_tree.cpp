#include <bits/stdc++.h>
using namespace std;

/*
input -->
10
5 4 2 8 6 9 10 3 1 7

output -->
Inorder traversal: 1 2 3 4 5 6 7 8 9 10 
Preorder traversal: 5 4 2 1 3 8 6 7 9 10 
Postorder traversal: 1 3 2 4 7 6 10 9 8 5 
Inorder traversal: 1 2 3 4 5 6 7 8 9 11 
Inorder traversal: 1 2 3 4 5 6 7 8 9 10 11 
Inorder traversal: 1 2 2 3 4 5 6 7 8 9 10 11

*/



struct Tree
{
    struct Node
    {
        Node *left;
        Node *right;
        int val;
    };

    Node *root;

    Tree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        Node *it = (Node *)malloc(sizeof(Node));
        it->val = value;
        it->left = nullptr;
        it->right = nullptr;

        if (!root)
        {
            root = it;
            return;
        }

        Node *curr = root;
        while (1)
        {
            if (value < curr->val)
            {
                if (curr->left != nullptr)
                {
                    curr = curr->left;
                }
                else
                {
                    Node *l = (Node *)malloc(sizeof(Node));
                    l->val = value;
                    l->left = nullptr;
                    l->right = nullptr;
                    curr->left = l;
                    break;
                }
            }
            else
            {
                if (curr->right != nullptr)
                {
                    curr = curr->right;
                }
                else
                {
                    Node *r = (Node *)malloc(sizeof(Node));
                    r->val = value;
                    r->left = nullptr;
                    r->right = nullptr;
                    curr->right = r;
                    break;
                }
            }
        }
    }

    void inorderTraversal()
    {
        inorder(root);
    }

    void preorderTraversal()
    {
        preorder(root);
    }

    void postorderTraversal()
    {
        postorder(root);
    }

    void inorder(Node *it)
    {
        if (!it)
            return;

        inorder(it->left);

        cout << it->val << ' ';

        inorder(it->right);
    }

    void preorder(Node *it)
    {
        if (!it)
            return;

        cout << it->val << ' ';

        preorder(it->left);

        preorder(it->right);
    }

    void postorder(Node *it)
    {
        if (!it)
            return;

        postorder(it->left);

        postorder(it->right);

        cout << it->val << ' ';
    }

    void replace_val(int replaceVal, int replaceWith)
    {
        replaceIt(root, replaceVal, replaceWith);
    }

    void replaceIt(Node *it, int replaceVal, int replaceWith)
    {
        if (!it)
            return;

        if (it->val == replaceVal)
        {
            it->val = replaceWith;
            return;
        }

        replaceIt(it->left, replaceVal, replaceWith);

        replaceIt(it->right, replaceVal, replaceWith);
    }
};

int main()
{
    Tree tree;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorderTraversal();
    cout << endl;

    tree.replace_val(10, 11);
    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    tree.insert(10);
    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    tree.insert(2);
    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    return 0;
}
