#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long long>>> adj;
vector<long long> dis;
#define inf 1000000000000000LL
vector<int> par;

void solve()
{
    int n, m;
    cin >> n >> m;
    dis = vector<long long>(n + 1, inf);
    adj = vector<vector<pair<int, long long>>>(n + 1);
    par = vector<int>(n + 1, -1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (q.size())
    {
        auto [c, u] = q.top();
        q.pop();
        for (auto [v, w] : adj[u])
        {
            long long tot = c + w;
            if (dis[v] > tot)
            {
                par[v] = u;
                dis[v] = tot;
                q.push({tot, v});
            }
        }
    }
    if (par[n] == -1)
        cout << "-1\n";
    else
    {
        int cur = n;
        vector<int> v;
        while (cur != -1)
        {
            v.push_back(cur);
            cur = par[cur];
        }
        reverse(v.begin(), v.end());
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
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