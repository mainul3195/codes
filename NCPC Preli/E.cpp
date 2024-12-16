#include <bits/stdc++.h>
using namespace std;
#define inf 1e18
int n;
vector<long long> a;
vector<vector<int>> adj;
vector<int> par;
int lg;
void dfs1(int u = 1, int p = 0)
{
    par[u] = p;
    for (auto v : adj[u])
        if (v != p)
            dfs1(v, u);
    return;
}
vector<vector<pair<long long, int>>> sp_table;
void build()
{
    lg = log2(n + .5) + 2;
    sp_table = vector<vector<pair<long long, int>>>(n + 2, vector<pair<long long, int>>(lg + 1, {inf, 0}));
    sp_table[0][0] = (pair<long long, int>){inf, 0};
    sp_table[1][0] = (pair<long long, int>){inf, 0};
    for (int i = 2; i <= n; i++)
    {
        sp_table[i][0] = {max(a[i - 1], a[par[i] - 1]), par[i]};
    }
    for (int k = 1; k < lg; k++)
        for (int i = 0; i <= n; i++)
        {
            int mid = sp_table[i][k - 1].second;
            long long mid_val = sp_table[i][k - 1].first;
            sp_table[i][k] = {max(mid_val, sp_table[mid][k - 1].first), sp_table[mid][k - 1].second};
        }
    return;
}
vector<long long> ans;
void dfs(int u = 1, int p = -1)
{
    int cur = u, len = 1;
    for (int k = lg - 1; k >= 0; k--)
    {
        if (sp_table[cur][k].first <= a[u - 1])
        {
            len += (1 << k);
            cur = sp_table[cur][k].second;
        }
    }
    cur = par[cur];
    ans[u] = ans[cur] + len * a[u - 1];
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u);
    return;
}
void solve()
{
    cin >> n;
    a = vector<long long>(n);
    ans = vector<long long>(n + 1, 0);
    ans[0] = 0;
    for (auto &i : a)
        cin >> i;
    adj = vector<vector<int>>(n + 1);
    par = vector<int>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1();
    build();
    dfs();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}