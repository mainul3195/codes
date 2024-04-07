#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define inf 100000000000000
int n, m;
vector<vector<pair<int, long long>>> adj;
vector<long long> dist, tot_routes, min_routes, max_routes;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int, long long>>>(n + 1);
    dist = vector<long long>(n + 1, inf);
    tot_routes = vector<long long>(n + 1, 0);
    max_routes = vector<long long>(n + 1, -inf);
    min_routes = vector<long long>(n + 1, inf);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, (long long)w});
    }
    dist[1] = 0;
    tot_routes[1] = 1;
    min_routes[1] = max_routes[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto [w, u] = q.top();
        q.pop();
        if (w > dist[u])
            continue;
        for (auto [v, c] : adj[u])
        {
            if (dist[v] < w + c)
                continue;
            if (dist[v] > w + c)
            {
                dist[v] = w + c;
                tot_routes[v] = tot_routes[u];
                min_routes[v] = min_routes[u] + 1;
                max_routes[v] = max_routes[u] + 1;
                q.push({w + c, v});
            }
            else
            {
                (tot_routes[v] += tot_routes[u]) %= mod;
                min_routes[v] = min(min_routes[v], min_routes[u] + 1);
                max_routes[v] = max(max_routes[v], max_routes[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << tot_routes[n] << " " << min_routes[n] << " " << max_routes[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}