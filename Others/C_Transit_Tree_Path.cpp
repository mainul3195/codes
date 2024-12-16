#include <bits/stdc++.h>
using namespace std;
vector<long long> dist;
vector<vector<pair<int, long long>>> adj;
void solve()
{
    int n;
    cin >> n;
    dist = vector<long long>(n + 1, 10000000000000000);
    adj = vector<vector<pair<int, long long>>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int q, k;
    cin >> q >> k;
    dist[k] = 0;
    priority_queue<pair<long long, int>> que;
    que.push({0, k});
    while (que.size())
    {
        auto [w, u] = que.top();
        que.pop();
        w = -w;
        for (auto [v, c] : adj[u])
        {
            long long tot = w + c;
            if (tot < dist[v])
            {
                dist[v] = tot;
                que.push({-tot, v});
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] << "\n";
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