#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> visited;
bool dfs(int u = 0, int col = 0)
{
    visited[u] = col;
    col = !col;
    bool ok = 1;
    for (auto v : adj[u])
    {
        if (visited[v] != -1 && visited[v] != col)
            return 0;
        if (visited[v] == -1)
            ok &= dfs(v, col);
    }
    return ok;
}
void solve()
{
    while (cin >> n && n)
    {
        adj = vector<vector<int>>(n);
        visited = vector<int>(n, -1);
        cin >> m;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (dfs())
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}