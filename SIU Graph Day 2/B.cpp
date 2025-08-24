#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> adj;
vector<int> visited;
void dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u])
        if (!visited[v])
            dfs(v);
}
void solve()
{
    cin >> n >> m >> k;
    adj = vector<vector<int>>(n + 1);
    visited = vector<int>(n + 1, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    while (k--)
    {
        int a;
        cin >> a;
        dfs(a);
    }
    int ans = 0;
    for (auto i : visited)
        if (i)
            ans++;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}