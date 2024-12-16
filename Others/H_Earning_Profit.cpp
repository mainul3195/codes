#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
struct nd
{
    int u, v;
    long long w;
};
vector<int> vis;
vector<vector<int>> adj;
bool dfs(int u)
{
    if(u == t)
        return 1;
    vis[u] = 1;
    bool ok = 0;
    for(auto v: adj[u])
        if(!vis[v])
            ok |= dfs(v);
    return ok;
}
void solve()
{
    cin >> n >> m >> s >> t;
    vector<nd> edges(m);
    vector<long long> dist(n + 1, -1000000000);
    vector<long long> prof(n + 1);
    adj = vector<vector<int>> (n + 1);
    vis = vector<int> (n+1, 0);
    for (auto &[u, v, w] : edges)
    {
        cin >> u >> v >> w;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        cin >> prof[i];
    dist[s] = 0;
    for (int i = 0; i < n; i++)
        for (auto [u, v, w] : edges)
        {
            long long cur = dist[u] + prof[v] - w;
            if (dist[v] < cur)
                dist[v] = cur;
        }
    long long temp = dist[t];
    for (int i = 0; i < n; i++)
        for (auto [u, v, w] : edges)
        {
            long long cur = dist[u] + prof[v] - w;
            if (dist[v] < cur)
                dist[v] = cur;
        }
    if (!dfs(s))
        cout << "Bad trip\n";
    else if (dist[t] != temp)
        cout << "Money hack!\n";
    else
        cout << dist[t] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}