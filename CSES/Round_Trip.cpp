#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis, path, ans;
int dfs(int u, int par = -1)
{
    vis[u] = 1;
    path.push_back(u);
    for (auto v : adj[u])
    {
        if (vis[v])
        {
            if (v != par)
            {
                ans.push_back(v);
                ans.push_back(u);
                return v;
            }
        }
        else
        {
            int t = dfs(v, u);
            if (t > 0)
                ans.push_back(u);
            if (t == u)
                t = -1;
            if (t)
                return t;
        }
    }
    path.pop_back();
    return 0;
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            ok |= dfs(i);
            if (ok)
            {
                cout << ans.size() << "\n";
                for (auto j : ans)
                    cout << j << " ";
                cout << "\n";
                break;
            }
        }
    if (!ok)
        cout << "IMPOSSIBLE\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}