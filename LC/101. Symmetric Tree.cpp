/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* class Solution
{
public:
    void dfs(TreeNode *node, vector<int> &v)
    {
        if (node)
        {
            if (node->left)
            {
                dfs(node->left, v);
            }
            else
            {
                v.push_back(-1);
            }
            if (node->right)
            {
                dfs(node->right, v);
            }
            else
            {
                v.push_back(-1);
            }

            v.push_back(node->val);
        }
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> vp, vq;
        dfs(p, vp);
        dfs(q, vq);

        if (vp == vq)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}; */
// shift + alt + A -- to comment out a paragraph --> /* */

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root)
        {
            return true;
        }
        TreeNode *p = nullptr, *q = nullptr;
        if(root->left)
        {
            p = root->left;
        }
        if(root->right)
        {
            q = root->right;
        }
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        queue<TreeNode *> sp ,sq;
        sp.push(p);
        sq.push(q);

        while (!sp.empty() && !sq.empty())
        {
            TreeNode *n1 = sp.front();
            TreeNode *n2 = sq.front();
            sp.pop();
            sq.pop();

            if (n1->val != n2->val)
            {
                return false;
            }
            if (n1->left && n2->right)
            {
                sp.push(n1->left);
                sq.push(n2->right);
            }
            else if (n1->left || n2->right)
            {
                return false;
            }
            if (n1->right && n2->left)
            {
                sp.push(n1->right);
                sq.push(n2->left);
            }
            else if (n1->right || n2->left)
            {
                return false;
            }
        }

        return sp.empty() && sq.empty();
    }
};

int main()
{
    Solution solve;

    return 0;
}