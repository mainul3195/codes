#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visited;
int n, m;
void dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u])
        if (!visited[v])
            dfs(v);
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> nodes;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            nodes.push_back(i);
            dfs(i);
        }
    cout << nodes.size() - 1 << "\n";
    for (int i = 0; i < nodes.size() - 1; i++)
        cout << nodes[i] << " " << nodes[i + 1] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}