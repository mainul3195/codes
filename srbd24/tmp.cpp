#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n;
void dfs(int u = 1, int p = -1)
{
    cout << u << "\n";
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u);
    return;
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
    cout << adj[1].size() << "\n";
    dfs();
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}