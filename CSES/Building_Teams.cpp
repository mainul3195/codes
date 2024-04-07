#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis;
bool dfs(int u, int col = 1)
{
    vis[u] = col;
    bool ok = 1;
    for(auto v: adj[u])
    {
        if(vis[v])
        {
            if(vis[v] == (col^3))
                continue;
            else return 0;
        }
        else
            ok &= dfs(v, col^3);
    }
    return ok;
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
    bool ok = 1;
    for (int i = 1; ok && i <= n; i++)
        if (!vis[i])
            ok &= dfs(i);
    if (ok)
    {
        for (int i = 1; i <= n; i++)
            cout << vis[i] << " ";
        cout << "\n";
    }
    else
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