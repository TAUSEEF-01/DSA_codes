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

class Solution
{
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l, r);
    }
};

int main()
{
    Solution solve;

    return 0;
}



const int M = 1e5+10;
vector<int> g[M];
int depth[M], height[M];


void dfs_for_trees(int vertex, int parent)
{
    for(int child:g[vertex])
    {
        if(child==parent) continue;
        depth[child]=depth[vertex] + 1;
        dfs_for_trees(child, vertex);
        height[vertex]=max(height[vertex], height[child] + 1);
    }
}


void graph_input()
{
    int n;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs_for_trees(1, -1);
}

void answer()
{
    graph_input();
}