#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<int> dis;
void solve()
{
    int n, m;
    cin >> n >> m;
    dis = vector<int>(n + 1, 2000000000);
    adj = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (q.size())
    {
        auto [c, u] = q.top();
        q.pop();
        for (auto [v, w] : adj[u])
        {
            int tot = c + w;
            if (dis[v] > tot)
            {
                dis[v] = tot;
                q.push({tot, v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << min(dis[i], 30000) << " \n"[i == n];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}