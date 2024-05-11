#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 7;
int parent[sz];
int node_rank[sz];

int find_parent(int v)
{
    if (v == parent[v])
        return v;

    int root = find_parent(parent[v]);
    parent[v] = root;
    return root;
}

void union_set(int u, int v)
{
    int parent_u = find_parent(u);
    int parent_v = find_parent(v);

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

void initialize_values()
{
    for (int i = 0; i < sz; i++)
    {
        parent[i] = i;
        node_rank[i] = 0;
    }
}

int main()
{
    initialize_values();

    union_set(1, 2);
    union_set(1, 3);
    union_set(4, 11);
    union_set(10, 12);
    union_set(10, 11);
    // union_set(6, 2);
    union_set(1, 10);
    union_set(6, 2);
    union_set(7, 8);
    union_set(7, 9);


    for (int i = 1; i <= 12; i++)
    {
        cout << "node " << i << " parent " << parent[i] << " rank " << node_rank[i] << endl;
    }

    return 0;
}


/*
            10                  7       5
    /   /   |   \    \          |
    2   1   4   6    12         8
        |   |
        3   11

*/