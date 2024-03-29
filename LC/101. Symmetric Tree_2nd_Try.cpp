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

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        TreeNode *p = root->left;
        TreeNode *q = root->right;

        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }

        stack<TreeNode *> sp, sq;
        sp.push(p);
        sq.push(q);

        while (!sp.empty() && !sq.empty())
        {
            TreeNode *vp = sp.top();
            TreeNode *vq = sq.top();

            sp.pop();
            sq.pop();

            if (vp->val != vq->val)
            {
                return false;
            }
            else
            {
                if (vp->left && vq->right)
                {
                    sp.push(vp->left);
                    sq.push(vq->right);
                }
                else if (vp->left || vq->right)
                {
                    return false;
                }

                if (vp->right && vq->left)
                {
                    sp.push(vp->right);
                    sq.push(vq->left);
                }
                else if (vp->right || vq->left)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}