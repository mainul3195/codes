#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n;
int mx_dist, dist_node;
void dfs(int u, int p = -1, int dis = 0)
{
    if (dis > mx_dist)
    {
        mx_dist = dis;
        dist_node = u;
    }
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u, dis + 1);
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mx_dist = dist_node = -1;
    dfs(1);
    mx_dist = -1;
    dfs(dist_node);
    cout << mx_dist << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}