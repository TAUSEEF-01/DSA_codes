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

struct Binary_tree
{
    struct Node
    {
        Node *left;
        Node *right;
        int val;
    };

    Node *root;

    Binary_tree()
    {
        root = nullptr;
    }

    Node *findBSTMin(Node *node)
    {
        while(node->left != nullptr)
        {
            node = node->left;
        }

        return node;
    }

    Node *deleteBSTMin(Node *node)
    {
        if(node == nullptr)
            return nullptr;

        if(node->left == nullptr)
        {
            Node* temp = node->right;
            free(node);
            return temp;
        }

        node->left = deleteBSTMin(node->left);
        return node;
    }

    Node *deleteNode(Node* node, int value)
    {
        if(node == nullptr)
            return nullptr;

        if(value < node->val)
        {
            node->left = deleteNode(node->left, value);
        }
        else if(value > node->val)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            if(node->left == nullptr && node->right == nullptr)
            {
                free(node);
                return nullptr;
            }
            else if(node->left == nullptr)
            {
                Node* temp = node->right;
                free(node);
                return temp;
            }
            else if(node->right == nullptr)
            {
                Node *temp = node->left;
                free(node);
                return temp;
            }

            Node* temp = findBSTMin(node->right);
            node->val = temp->val;
            node->right = deleteBSTMin(node->right);
        }

        return node;
    }

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->val = value;
            temp->left = nullptr;
            temp->right = nullptr;

            return temp;
        }

        if (node->val > value)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Node *deleteNode(Node *node, int value)
    // {
    //     if(node == nullptr)
    //     {
    //         return node;
    //     }


    //     if(node->val > value)
    //     {
    //         node->left = deleteNode(node->left, value);
    //         return node;
    //     }
    //     else if(node->val < value)
    //     {
    //         node->right = deleteNode(node->right, value);
    //         return node;
    //     }


    //     if(node->left == nullptr)
    //     {
    //         Node *temp = node->right;
    //         node = nullptr;
    //         return temp;
    //     }
    //     else if(node->right == nullptr)
    //     {
    //         Node *temp = node->left;
    //         node = nullptr;
    //         return  temp;
    //     }
    //     else 
    //     {
    //         Node* succP = node;
    //         Node * succ = node->right;

    //         while(succ->left != nullptr)
    //         {
    //             succP = succ;
    //             succ = succ->left;
    //         }

    //         if(succP != node)
    //         {
    //             succP->left = succ->right;
    //         }
    //         else 
    //         {
    //             succP->right = succ->right;
    //         }

    //         succ = nullptr;
    //         return node;
    //     }
    // }

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

};

int main()
{
    Binary_tree tree;
    Binary_tree t2;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // tree.insert(x);

        t2.root = t2.insert(t2.root, x);
    }


    // using recursion ------------->
    cout << "Inorder traversal: ";
    t2.inorderTraversal();
    cout << endl;


    t2.deleteNode(t2.root, 5);
    cout << "Inorder traversal: ";
    t2.inorderTraversal();
    cout << endl;

    return 0;
}
