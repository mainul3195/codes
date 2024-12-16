#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> par, dist;
void conf()
{
    par = vector<int>(n + 1, -1);
    dist = vector<int>(n + 1, 2000000000);
    return;
}
map<pair<int, int>, int> mp;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        mp[{u, v}] = mp[{v, u}] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        priority_queue<pair<int, int>> q;
        int s = i;
        conf();
        q.push({0, s});
        par[s] = -1;
        dist[s] = 0;
        while (q.size())
        {
            auto [w, u] = q.top();
            w = -w;
            q.pop();
            for (auto [v, c] : adj[u])
            {
                int cost = w + c;
                if (cost < dist[v])
                {
                    dist[v] = cost;
                    q.push({-cost, v});
                    par[v] = u;
                }
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            int cur = j;
            while (par[cur] != -1)
            {
                mp[{cur, par[cur]}] = mp[{par[cur], cur}] = 1;
                cur = par[cur];
            }
        }
    }
    int cnt = 0;
    for (auto [a, b] : mp)
    {
        if (!b)
            cnt++;
    }
    cout << cnt / 2 << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}