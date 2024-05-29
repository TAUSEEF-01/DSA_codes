#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
vector<int> g[sz];
bool vis[sz];

void dfs(int u)
{
    vis[u] = true;
    cout << "node: " << u << " visited!" << endl;

    for (auto &v : g[u])
    {
        if (vis[v])
        {
            continue;
        }
        dfs(v);
    }
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << "node: " << u << " visited!" << endl;

        for (auto &v : g[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
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
    // bfs(1);

    return 0;
}
