#include <bits/stdc++.h>
using namespace std;

const int dfs_limit = 1e5 + 10;
vector<int> g[dfs_limit];
vector<bool> vis(dfs_limit, false);

void dfs(int u)
{
    vis[u] = true;
    cout << "node: " << u << " visited!\n";
    for (int &v : g[u])
    {
        if (vis[v])
        {
            continue;
        }

        dfs(v);
    }
}

int main()
{
    int nodes;
    cin >> nodes;

    for (int i = 0; i < nodes - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
}
