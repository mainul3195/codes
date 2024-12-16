#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
void dfs(int u)
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
    adj = vector<vector<int>>(n + 1);
    vis = vector<int>(n + 1, 0);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v);
        adj[v].push_back(u - 1);
    }
    dfs(0);
    if (vis[n])
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