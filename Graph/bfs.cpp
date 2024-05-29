#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 10;
vector<int> g[M];

bool vis[M];
// int level[M];

void bfs(int source)
{
    queue<int> a;
    a.push(source);
    vis[source] = true;

    while (!a.empty())
    {
        int current_vertex = a.front();
        a.pop();
        cout << "node: " << current_vertex << " visited!\n";
        for (auto child : g[current_vertex])
        {
            if (!vis[child])
            {
                a.push(child);
                vis[child] = true;
                // level[child] = level[current_vertex] + 1;
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

    bfs(1);
}
