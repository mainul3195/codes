#include <bits/stdc++.h>
using namespace std;
int n, m, x;
vector<vector<int>> adj;
vector<int> vis;
vector<int> state;
bool find(int u)
{
    if (vis[u])
        return state[u];
    vis[u] = 1;
    bool ok = 0;
    for (auto v : adj[u])
    {
        if (find(v) == 0)
            ok = 1;
    }
    return ok;
}
void solve()
{
    cin >> n >> m >> x;
    adj = vector<vector<int>>(n + 1);
    vis = state = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if (find(x))
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}