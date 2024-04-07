#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> sp_table;
vector<int> level, pls, mns;
void find_parent(int u = 1, int par = -1, int lvl = 0)
{
    sp_table[u][0] = par;
    level[u] = lvl;
    for (auto v : adj[u])
        if (v != par)
            find_parent(v, u, lvl + 1);
}
int find(int u = 1, int par = -1)
{
    int tot = 0;
    for (auto v : adj[u])
        if (v != par)
            tot += find(v, u);
    tot += pls[u];
    return pls[u] = tot;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    adj = vector<vector<int>>(n + 1, vector<int>());
    sp_table = vector<vector<int>>(n + 1, vector<int>(log2(n) + 2, -1));
    pls = mns = level = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_parent();
    int lim = log2(n) + 1;
    for (int k = 1; k < lim; k++)
        for (int i = 1; i <= n; i++)
            if (sp_table[i][k - 1] != -1)
                sp_table[i][k] = sp_table[sp_table[i][k - 1]][k - 1];
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j <= lim; j++)
    //         cout << sp_table[i][j] << " ";
    //     cout << "\n";
    // }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        pls[a]++;
        pls[b]++;
        // cout << a << " " << b << "\n";
        if (level[a] < level[b])
            a ^= b ^= a ^= b;
        // cout << a << " " << b << "\n\n";
        int u = a, v = b;
        int dif = level[a] - level[b];
        // cout << dif << endl;
        for (int i = lim; i >= 0; i--)
            if ((1LL << i) <= dif)
            {
                u = sp_table[u][i];
                dif -= (1 << i);
            }
        if (u == v)
        {
            pls[u]--;
            if (u != 1)
                pls[sp_table[u][0]]--;
            continue;
        }
        // cout << u << " " << v << "\n";
        for (int i = lim; i >= 0; i--)
        {
            int pu = sp_table[u][i];
            int pv = sp_table[v][i];
            if (pv != pu)
            {
                u = pu;
                v = pv;
            }
        }
        pls[sp_table[u][0]]--;
        if (sp_table[u][0] != 1)
            pls[sp_table[u][1]]--;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << i << " -> " << pls[i] << "\n";
    find();
    for (int i = 1; i <= n; i++)
        cout << pls[i] << " ";
    cout << "\n";
    return 0;
}
