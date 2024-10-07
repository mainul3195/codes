#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<vector<int>> adj, spt;
vector<int> par, level, child;
int dfs(int u = 1, int p = -1, int l = 1)
{
    int tot_child = 0;
    par[u] = p;
    level[u] = l;
    for (auto v : adj[u])
        if (v != p)
            tot_child += dfs(v, u, l + 1);
    return child[u] = tot_child + 1;
}
int lim;

pair<int, int> calc(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    int dif = level[u] - level[v];
    int dis = dif;
    for (int k = lim - 1; k >= 0 && dif; k--)
    {
        if ((1 << k) <= dif)
        {
            dif -= (1 << k);
            u = spt[u][k];
        }
    }
    if (u == v)
        return {u, dis};
    for (int k = lim - 1; k >= 0; k--)
    {
        if (spt[u][k] != spt[v][k])
        {
            u = spt[u][k];
            v = spt[v][k];
            dis += (1 << (k + 1));
        }
    }
    return {par[u], dis + 2};
}
int lca(int u, int v)
{
    return calc(u, v).first;
}
int dis(int u, int v)
{
    return calc(u, v).second;
}

void solve()
{
    cin >> n >> q;
    child = vector<int>(n + 1, 0);
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    level = vector<int>(n + 1, 0);
    par = vector<int>(n + 1, -1);
    dfs();
    // for (int i = 1; i <= n; i++)
    //     cout << i << " -> " << child[i] << "\n";
    lim = log2(n + .5) + 2;
    spt = vector<vector<int>>(n + 1, vector<int>(lim, -1));
    for (int i = 1; i <= n; i++)
        spt[i][0] = par[i];
    for (int k = 1; k < lim; k++)
        for (int i = 1; i <= n; i++)
            if (spt[i][k - 1] != -1)
                spt[i][k] = spt[spt[i][k - 1]][k - 1];
    par[1] = 0;
    while (q--)
    {
        int a, b, c, mid;
        cin >> a >> b >> c;
        auto [lab, dab] = calc(a, b);
        auto [lac, dac] = calc(a, c);
        auto [lbc, dbc] = calc(b, c);
        if (dab + dbc == dac)
        {
            mid = b;
        }
        else if (dac + dbc == dab)
        {
            mid = c;
        }
        else if (dab + dac == dbc)
        {
            mid = a;
        }
        else
        {
            cout << "0\n";
            continue;
        }
        // cout << mid << "..\n";
        if ((lab == lbc) && (lbc == lac) && (lac == lab))
        {
            if (lab == c)
            {
                cout << n - child[c] + 1 << "\n";
            }
            else
            {
                cout << child[c] << "\n";
            }
        }
        else
        {
            if (mid == c)
            {
                int under;
                if (lac == c)
                {
                    under = a;
                }
                else
                {
                    under = b;
                }
                // cout << "Under - " << under << "\n";
                cout << child[c] - child[under] - (dis(under, c) - 1) << "\n";
            }
            else
            {
                cout << child[c] << "\n";
            }
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}