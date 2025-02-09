#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
void dfs(int u = 1)
{
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v])
            dfs(v);
    return;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    adj = vector<vector<int>>(n + 2, vector<int>());
    vis = vector<int>(n + 3, 0);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + 1);
        adj[v + 1].push_back(u);
    }
    dfs();
    if (vis[n + 1])
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}