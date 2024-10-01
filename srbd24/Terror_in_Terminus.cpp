// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> adj, spt;
// int n, lim;
// void dfs(int u = 1, int p = -1)
// {
//     cout << u << "\n";
//     for (auto v : adj[u])
//         if (v != p)
//             dfs(v, u);
//     return;
// }
// void solve()
// {
//     cin >> n;
//     // lim = log2(n) + 5;
//     // vector<vector<int>> spt(n + 1, vector<int>(lim, 0));
//     vector<vector<int>> adj(n + 1);
//     for (int i = 1; i < n; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << " -> ";
//         for (auto u : adj[i])
//             cout << u << " ";
//         cout << "\n";
//     }
//     // cout << "ok\n";

//     // dfs();
//     // for (int k = 1; k < lim; k++)
//     //     for (int i = 1; i <= n; i++)
//     //         spt[i][k] = spt[spt[i][k - 1]][k - 1];
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << i << " -> ";
//     //     for (int j = 0; j < lim; j++)
//     //         cout << spt[i][j] << " ";
//     //     cout << "\n";
//     // }
//     // int q;
//     // cin >> q;
//     // while (q--)
//     // {
//     //     int u, v;
//     //     cin >> u >> v;
//     // }
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, spt;
vector<int> par, level;
int n, lim;
void dfs(int u = 1, int p = -1, int lvl = 1)
{
    par[u] = p;
    level[u] = lvl;
    // cout << u << "\n";
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u, lvl + 1);
    return;
}

void solve()
{
    cin >> n;
    lim = log2(n + .5) + 5;
    par = vector<int>(n + 1, -1);
    level = vector<int>(n + 1, 0);
    vector<vector<int>> spt(n + 1, vector<int>(lim, -1));
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    for (int i = 1; i <= n; i++)
        spt[i][0] = par[i];
    for (int k = 1; k < lim; k++)
        for (int i = 1; i <= n; i++)
            if (spt[i][k - 1] != -1)
                spt[i][k] = spt[spt[i][k - 1]][k - 1];

    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < lim; j++)
    //         cout << spt[i][j] << " ";
    //     cout << "\n";
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (u == v || (par[u] == v || par[v] == u))
            cout << u << "\n";
        else
        {
            int tu = u, tv = v, lca;
            if (level[u] < level[v])
                swap(u, v);
            int dif = level[u] - level[v];
            for (int k = lim - 1; k >= 0; k--)
            {
                if ((1LL << k) <= dif)
                {
                    dif -= (1 << k);
                    u = spt[u][k];
                }
            }
            if (u == v)
                lca = u;
            else
            {
                for (int k = lim - 1; k >= 0; k--)
                    if (spt[u][k] != spt[v][k])
                    {
                        u = spt[u][k];
                        v = spt[v][k];
                    }
                lca = par[u];
            }
            int d1 = level[tu] - level[lca], d2 = level[tv] - level[lca];
            int tot = d1 + d2;
            int to_go = tot / 2;
            if (d1 >= to_go)
            {
                for (int k = lim - 1; k >= 0; k--)
                {
                    if ((1LL << k) <= to_go)
                    {
                        to_go -= (1 << k);
                        tu = spt[tu][k];
                    }
                }
                cout << tu << "\n";
            }
            else
            {
                to_go = tot - to_go;
                for (int k = lim - 1; k >= 0; k--)
                {
                    if ((1LL << k) <= to_go)
                    {
                        to_go -= (1 << k);
                        tv = spt[tv][k];
                    }
                }
                cout << tv << "\n";
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}