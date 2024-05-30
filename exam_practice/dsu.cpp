#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 7;
int parent[sz];
int node_rank[sz];
int node_size[sz];

void initialize()
{
    for (int i = 0; i < sz; i++)
    {
        parent[i] = i;
        node_rank[i] = 1;
        node_size[i] = 1;
    }
}

int findParent(int v)
{
    if (v == parent[v])
        return v;

    int root = findParent(parent[v]);
    parent[v] = root;
    return root;
}

void unionSet(int u, int v)
{
    int parent_u = findParent(u);
    int parent_v = findParent(v);

    if (parent_u != parent_v)
    {
        if (node_rank[parent_u] < node_rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else
        {
            parent[parent_v] = parent_u;
            if (node_rank[parent_u] == node_rank[parent_v])
            {
                node_rank[parent_u]++;
            }
        }
    }
}

void UnionSet(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a != b)
    {
        if (node_size[a] < node_size[b])
            swap(a, b);

        parent[b] = a;
        node_size[a] += node_size[b];
    }
}

int main()
{
    initialize();

    // DSU by rank --------------->

    // unionSet(1, 2);
    // unionSet(1, 3);
    // unionSet(4, 11);
    // unionSet(10, 12);
    // unionSet(10, 11);
    // // unionSet(6, 2);
    // unionSet(1, 10);
    // unionSet(6, 2);
    // unionSet(7, 8);
    // unionSet(7, 9);

    // cout << "DEPTH wise --->\n";

    // for (int i = 1; i <= 12; i++)
    // {
    //     cout << "node " << i << " parent " << parent[i] << " rank " << node_rank[i] << endl;
    // }

    // cout << endl
    //      << endl;

    // DSU by size --------------->

    UnionSet(1, 2);
    UnionSet(1, 3);
    UnionSet(4, 11);
    UnionSet(10, 12);
    UnionSet(10, 11);
    // UnionSet(6, 2);
    UnionSet(1, 10);
    UnionSet(6, 2);
    UnionSet(7, 8);
    UnionSet(7, 9);
    cout << "TOTAL NODE wise --->\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << "node " << i << " parent " << parent[i] << " rank " << node_size[i] << endl;
    }

    return 0;
}
