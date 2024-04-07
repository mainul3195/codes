#include <bits/stdc++.h>
using namespace std;
long long a[200005], bit[200005], strt[200005], e[200005];
vector<vector<int>> adj(200005);
int n, q;
void update(int ind, int x)
{
    for (; ind <= n; ind += (ind & (-ind)))
        bit[ind] += x;
}
long long query(int ind)
{
    long long tot = 0;
    for (; ind; ind -= (ind & (-ind)))
        tot += bit[ind];
    return tot;
}
int discovery_time = 1;
void dfs(int u = 1, int p = -1)
{
    strt[u] = discovery_time;
    update(discovery_time, a[u]);
    for (auto v : adj[u])
        if (v != p)
        {
            discovery_time++;
            dfs(v, u);
        }
    e[u] = discovery_time;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int nd, nw;
            cin >> nd >> nw;
            update(strt[nd], nw - query(strt[nd]) + query(strt[nd] - 1));
        }
        else
        {
            int nd;
            cin >> nd;
            cout << query(e[nd]) - query(strt[nd] - 1) << "\n";
        }
    }
    return 0;
}