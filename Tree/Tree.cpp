#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    struct Node
    {
        Node *left;
        Node *right;
        int val;
    };

    Node *root;
    Node *temp;

    Tree()
    {
        root = nullptr;
        temp = nullptr;
    }

    void insert_root(int value)
    {
        root = (Node *)malloc(sizeof(Node));
        root->val = value;
        root->left = nullptr;
        root->right = nullptr;
    }

    void insertForBuildingTree(int parent, int child, int pos)
    {
        Node *it = (Node *)malloc(sizeof(Node));
        it->val = child;
        it->left = nullptr;
        it->right = nullptr;

        temp = nullptr;

        if (node_inorder(root, parent))
        {
            if (pos)
            {
                temp->right = it;
            }
            else
            {
                temp->left = it;
            }
        }
        else
        {
            cout << "NO\n";
        }
    }

    bool node_inorder(Node *it, int value)
    {
        if (!it)
        {
            return false;
        }

        if (it->val == value)
        {
            temp = it;
            return true;
        }

        bool ok1 = node_inorder(it->left, value);
        bool ok2 = node_inorder(it->right, value);

        return (ok1 | ok2);
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

    int rootVal;
    cin >> rootVal;

    tree.insert_root(rootVal);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int parent, child, pos;
        cin >> parent >> child >> pos;
        tree.insertForBuildingTree(parent, child, pos);
    }

    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Postorder tra versal: ";
    tree.postorderTraversal();
    cout << endl;

    tree.replace_val(1, 11);
    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    return 0;
}
