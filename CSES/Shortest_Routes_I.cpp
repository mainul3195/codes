#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, long long>>> adj;
vector<long long> dis;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int, long long>>>(n + 1);
    dis = vector<long long>(n + 1, 9223372036854775807);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dis[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto [w, u] = q.top();
        q.pop();
        if (dis[u] < w)
            continue;
        for (auto [v, c] : adj[u])
            if (w + c < dis[v])
            {
                dis[v] = w + c;
                q.push({dis[v], v});
            }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}