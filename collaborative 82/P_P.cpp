#include <bits/stdc++.h>
using namespace std;
long long n, m, q, t;
vector<tuple<int, int, long long>> edges;
vector<vector<int>> par;

int find_par(int k, int u)
{
    if (par[k][u] == u)
        return u;
    return par[k][u] = find_par(k, par[k][u]);
}

void solve()
{
    cin >> n >> m >> q >> t;
    par = vector<vector<int>>(62, vector<int>(n + 1, -1));
    for (int i = 0; i < 62; i++)
        for (int j = 0; j < n + 1; j++)
            par[i][j] = j;
    edges = vector<tuple<int, int, long long>>(m);
    for (auto &[u, v, w] : edges)
        cin >> u >> v >> w;
    int lim = log2(t + .5) + 1;
    for (auto [u, v, w] : edges)
    {
        for (int i = lim; i < 61; i++)
            if (w & (1LL << i))
            {
                int pu = find_par(i, u);
                int pv = find_par(i, v);
                par[i][pu] = pv;
            }
        if ((w & t) == t)
        {
            int pu = find_par(61, u);
            int pv = find_par(61, v);
            par[61][pu] = pv;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        int pu = find_par(61, u);
        int pv = find_par(61, v);
        if (pu == pv)
            cout << "Yes\n";
        else
        {
            for (int i = 0; i < 61; i++)
            {
                int pu = find_par(i, u);
                int pv = find_par(i, v);
                if (pu == pv)
                {
                    cout << "Yes\n";
                    return;
                }
            }
            cout << "No\n";
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