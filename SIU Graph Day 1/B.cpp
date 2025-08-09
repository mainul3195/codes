#include <bits/stdc++.h>
using namespace std;
#define mx 100005
vector<vector<int>> adj;
int n, m, cat[mx];

int dfs(int u = 1, int par = -1, int consecutive = 0)
{
    if (cat[u] == 1)
        consecutive++;
    else
        consecutive = 0;

    if (consecutive > m)
        return 0;
    if ((adj[u].size() == 1) && (u != 1))
        return 1;

    int tot = 0;
    for (auto v : adj[u])
        if (v != par)
            tot += dfs(v, u, consecutive);
    return tot;
}

void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs() << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}