#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<vector<int>> adj;
vector<long long> val;
map<int, long long> mp;
vector<vector<int>> spt;
vector<int> lvl, in, out;
int lim;
void dfs(int u = 1, int p = -1, int l = 1)
{
    lvl[u] = l;
    spt[u][0] = p;
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u, l + 1);
    return;
}
int lca(int u, int v)
{
    if (lvl[u] < lvl[v])
        swap(u, v);
    int dif = lvl[u] - lvl[v];
    for (int k = lim - 1; k >= 0 && dif; k--)
    {
        if ((1LL << k) <= dif)
        {
            dif -= (1LL << k);
            u = spt[u][k];
        }
    }
    if (u == v)
        return u;
    for (int k = lim - 1; k >= 0; k--)
    {
        if (spt[u][k] != spt[v][k])
        {
            u = spt[u][k];
            v = spt[v][k];
        }
    }
    return spt[u][0];
}
void solve()
{
    cin >> n >> q;
    lim = log2(n + .5) + 2;
    lvl = vector<int>(n + 1, 0);
    spt = vector<vector<int>>(n + 1, vector<int>(lim, -1));
    adj = vector<vector<int>>(n + 1);
    val = vector<long long>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    mp.clear();
    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(val[i]) == mp.end())
            mp[val[i]] = (long long)rand() * rand();
        val[i] = mp[val[i]];
    }
    dfs();
    for (int k = 1; k < lim; k++)
        for (int i = 1; i <= n; i++)
            if (spt[i][k - 1] != -1)
                spt[i][k] = spt[spt[i][k - 1]][k - 1];

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}