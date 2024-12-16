#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> degree, disa, disb;
int n, f, s;
void dfs(int u, vector<int> &dis, int d)
{
    dis[u] = d;
    for (auto v : adj[u])
        if (!dis[v])
            dfs(v, dis, d + 1);
    return;
}
void solve()
{
    cin >> n >> f >> s;
    adj = vector<vector<int>>(n + 1);
    degree = disa = disb = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    dfs(f, disa, 1);
    dfs(s, disb, 1);
    // for (int i = 1; i <= n; i++)
    //     cout << disa[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << disb[i] << " ";
    // cout << "\n";
    vector<int> candidates;
    for (int i = 1; i <= n; i++)
        if (degree[i] == 1)
            candidates.push_back(adj[i][0]);
    int ans = 0;
    for (auto i : candidates)
        if (disa[i] <= disb[i])
            ans = max(ans, disb[i] - 1);
    if (degree[f] == 1 && adj[f][0] == s)
        ans = 0;
    else if (degree[f] == 1 && degree[s] == 1 && adj[f][0] == adj[s][0])
        ans = 1;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}