#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<vector<pair<long long, long long>>> adj;
vector<int> par, visited;
vector<vector<pair<int, int>>> sparse_table;
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
void dfs(int u, int par = -1, int lvl = 1)
{
    visited[u] = lvl;
    for (auto [v, w] : adj[u])
        if (v != par)
        {
            sparse_table[v][0] = {u, w};
            dfs(v, u, lvl + 1);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    adj = vector<vector<pair<long long, long long>>>(n + 1);
    par = visited = vector<int>(n + 1, 0);
    int lim = log2(n) + 2;
    sparse_table = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(lim, {-1, 1000000000}));
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int t = 1; t <= m; t++)
    {
        int u, v;
        cin >> u >> v;
        int pu = getpar(u);
        int pv = getpar(v);
        if (pu != pv)
        {
            par[pu] = pv;
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
    for (int k = 1; k < lim; k++)
        for (int i = 1; i <= n; i++)
            if (sparse_table[i][k - 1].first != -1)
            {
                sparse_table[i][k].first = sparse_table[sparse_table[i][k - 1].first][k - 1].first;
                sparse_table[i][k].second = max(sparse_table[i][k - 1].second, sparse_table[sparse_table[i][k - 1].first][k - 1].second);
            }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int pa = getpar(a);
        int pb = getpar(b);
        if (pa != pb)
        {
            cout << "-1\n";
            continue;
        }
        int la = visited[a];
        int lb = visited[b];
        if (la < lb)
            a ^= b ^= a ^= b, la ^= lb ^= la ^= lb;
        int dif = la - lb;
        int ans = 0;
        for (int i = lim - 1; i >= 0; i--)
            if ((1 << i) <= dif)
            {
                dif -= 1 << i;
                ans = max(ans, sparse_table[a][i].second);
                a = sparse_table[a][i].first;
            }
        if (a == b)
        {
            cout << ans << "\n";
            continue;
        }
        for (int i = lim - 1; i >= 0; i--)
            if (sparse_table[a][i].first != sparse_table[b][i].first)
            {
                ans = max({ans, sparse_table[a][i].second, sparse_table[b][i].second});
                a = sparse_table[a][i].first;
                b = sparse_table[b][i].first;
            }
        ans = max({ans, sparse_table[a][0].second, sparse_table[b][0].second});
        cout << ans << "\n";
    }
    return 0;
}