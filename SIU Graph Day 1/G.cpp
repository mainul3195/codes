#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
int dfs(int u, int p)
{
    for (auto [v, w] : adj[u])
        if (v != p)
        {
            if (v == 1)
                return w;
            return w + dfs(v, u);
        }
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, c});
    }
    int p1 = adj[1][0].first;
    int p2 = adj[1][1].first;
    int cost1 = dfs(1, p1);
    int cost2 = dfs(1, p2);
    cout << min(cost1, cost2) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}