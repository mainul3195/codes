#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis, inStack, cycle;
int dfs(int u)
{
    vis[u] = 1;
    inStack[u] = 1;
    for (auto v : adj[u])
    {
        if (vis[v] && inStack[v])
        {
            cycle.push_back(v);
            cycle.push_back(u);
            return v;
        }
        else if (!vis[v])
        {
            int t = dfs(v);
            if (t > 0)
            {
                cycle.push_back(u);
                if (t == u)
                    t = -1;
                return t;
            }
            else if (t)
                return t;
        }
    }
    inStack[u] = 0;
    return 0;
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = inStack = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            int ok = dfs(i);
            if (ok)
            {
                cout << cycle.size() << "\n";
                reverse(cycle.begin(), cycle.end());
                for (auto i : cycle)
                    cout << i << " ";
                cout << "\n";
                return;
            }
        }
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