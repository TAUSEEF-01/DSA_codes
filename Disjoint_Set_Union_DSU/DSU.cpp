#include <bits/stdc++.h>
using namespace std;

// DEPTH wise --->
const int sz = 1e5 + 7;
int parent_depth_wise[sz];
int node_rank[sz];

int find_parent(int v)
{
    if (v == parent_depth_wise[v])
        return v;

    int root = find_parent(parent_depth_wise[v]);
    parent_depth_wise[v] = root; // path compression
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
            parent_depth_wise[parent_u] = parent_v;
        }
        else
        {
            parent_depth_wise[parent_v] = parent_u;
            if (node_rank[parent_u] == node_rank[parent_v])
            {
                node_rank[parent_u]++;
            }
        }
    }
}

// TOTAL NODE wise --->
const int val_dsu = 1e5 + 10;
int parent[val_dsu];
int dsu_size[val_dsu];

int find(int v)
{
    if (v == parent[v])
        return v;
    // path compression:
    return parent[v] = find(parent[v]);
}

void Union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        // union by size:
        if (dsu_size[a] < dsu_size[b])
            swap(a, b);
        parent[b] = a;
        dsu_size[a] += dsu_size[b];
    }
}

// void make(int v)
// {
//     parent[v] = v;
//     dsu_size[v] = 1;
// }

void initialize_values()
{
    for (int i = 0; i < sz; i++)
    {
        parent_depth_wise[i] = i;
        node_rank[i] = 1;
        
        parent[i] = i;
        dsu_size[i] = 1;
    }
}

int main()
{
    initialize_values();

    // for (int i = 0; i < val_dsu; i++)
    // {
    //     make(i);
    // }

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

    cout << "DEPTH wise --->\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << "node " << i << " parent " << parent_depth_wise[i] << " rank " << node_rank[i] << endl;
    }

    cout << endl
         << endl;

    Union_set(1, 2);
    Union_set(1, 3);
    Union_set(4, 11);
    Union_set(10, 12);
    Union_set(10, 11);
    // Union_set(6, 2);
    Union_set(1, 10);
    Union_set(6, 2);
    Union_set(7, 8);
    Union_set(7, 9);
    cout << "TOTAL NODE wise --->\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << "node " << i << " parent " << parent[i] << " rank " << dsu_size[i] << endl;
    }

    return 0;
}

/*
            10                     7       5
    /   /   |   \    \          /     \
    2   1   4   6    12         8     9
        |   |
        3   11

*/
