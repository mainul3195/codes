#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, long long>>> adj;
long long dist[2][100005];
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int, long long>>>(n + 1);
    map<pair<int, int>, long long> mp;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (mp.count({u, v}))
            mp[{u, v}] = min(mp[{u, v}], (long long)w);
        else
            mp[{u, v}] = w;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        adj[(*it).first.first].push_back({(*it).first.second, (*it).second});
    for (int i = 0; i <= n; i++)
        dist[0][i] = dist[1][i] = 9223372036854775807LL;
    priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<>> q;
    dist[0][1] = 0;
    q.push({0, 1, 0});
    while (q.size())
    {
        auto [w, u, t] = q.top();
        q.pop();
        if (dist[t][u] < w)
            continue;
        if (!t)
        {
            for (auto [v, c] : adj[u])
            {
                if (w + c < dist[0][v])
                {
                    dist[0][v] = w + c;
                    q.push({w + c, v, 0});
                }
                if (w + c / 2 < dist[1][v])
                {
                    dist[1][v] = w + c / 2;
                    q.push({w + c / 2, v, 1});
                }
            }
        }
        else
        {
            for (auto [v, c] : adj[u])
                if (w + c < dist[1][v])
                {
                    dist[1][v] = w + c;
                    q.push({w + c, v, 1});
                }
        }
    }
    cout << min(dist[1][n], dist[0][n]) << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}