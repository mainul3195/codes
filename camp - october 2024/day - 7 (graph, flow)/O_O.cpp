#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n, m;
vector<int> dist;
void solve()
{
    cin >> n >> m;
    dist = vector<int>(n + 1);
    adj = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> dist[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!dist[i])
        {
            bool ok = 1;
            for (int v : adj[i])
            {
                if (dist[v] != 1)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << i << "\n";
                return;
            }
        }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}