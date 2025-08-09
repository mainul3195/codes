#include <bits/stdc++.h>
using namespace std;
#define inf 1e18
#define mx 100005
struct nd
{
    int u;
    long long w;
    bool operator<(const nd &a) const
    {
        return w > a.w;
    }
};
int n, m, parent[mx];
long long dist[mx];

vector<vector<pair<int, long long>>> adj;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int, long long>>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
        dist[i] = inf, parent[i] = -1;
    dist[1] = 0;
    priority_queue<nd> q;
    q.push({1, 0});

    while (q.size())
    {
        auto [u, cost] = q.top();
        q.pop();
        if (cost > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            long long new_cost = cost + w;
            if (new_cost < dist[v])
            {
                parent[v] = u;
                dist[v] = new_cost;
                q.push({v, new_cost});
            }
        }
    }

    if (dist[n] == inf)
    {
        cout << "-1\n";
        return;
    }

    vector<int> path;
    int current = n;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " \n"[i == path.size() - 1];
    return;

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}