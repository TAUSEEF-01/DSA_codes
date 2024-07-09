#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(a) a.begin(), a.end()
#define reall(a) a.rbegin(), a.rend()
#define vsort(a) sort(all(a))
#define revsort(a) sort(reall(a))
#define vmin(a) *min_element(all(a))
#define vmax(a) *max_element(all(a))
#define loop(i, k, n) for (ll i = k; i < n; i++)
#define Loop(i, k, n) for (ll i = k; i <= n; i++)
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using pii = pair<int, int>;

/**/
#define input(a)      \
    for (auto &x : a) \
        cin >> x;

#define output(a)         \
    for (auto &x : a)     \
        cout << x << ' '; \
    cout << endl;

/**/
#define yes \
    cout << "YES\n"

#define no \
    cout << "NO\n"

/**/
const ll mod = 1e9 + 7, inf = 1e18;
const double pi = acos(-1);
#define dbg(a) cerr << __LINE__ << ": " << #a << " = " << a << '\n'


int dijkstra(int s, vector<vector<pair<int, int>>> &adj, int n)
{
    vector<int> d(n + 1, INT_MAX), p(n + 1, -1);

    d[s] = 0;

    using pii = pair<int, int>;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});

    while (!q.empty())
    {
        int v = q.top().second;
        q.pop();

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INT_MAX)
            return -1;
        ans = max(ans, d[i]);
    }

    return ans;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &vec : times)
    {
        adj[vec[0]].push_back({vec[1], vec[2]});
    }
    return dijkstra(k, adj, n);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> times(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        times[i].push_back(u);
        times[i].push_back(v);
        times[i].push_back(w);
    }

    cout << networkDelayTime(times, n, k) << endl;
}

/*
input:
4 3 2
2 1 1
2 3 1
3 4 1

output: 
2
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
