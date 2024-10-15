#include <bits/stdc++.h>
using namespace std;

struct XorBasis
{
    vector<int> basis;
    int N = 0, tmp = 0;
    void add(int x)
    {
        N++;
        tmp |= x;
        for (auto &i : basis)
            x = min(x, x ^ i);
        if (!x)
            return;
        for (auto &i : basis)
            if ((i ^ x) < i)
                i ^= x;
        basis.push_back(x);
        sort(basis.begin(), basis.end());
    }

    void clear()
    {
        N = 0;
        tmp = 0;
        basis.clear();
    }

    int minxor(int x = 0)
    {
        for (auto &i : basis)
            x = min(x, x ^ i);
        return x;
    }
} xb;
vector<vector<pair<int, int>>> adj;
vector<int> xr;
int n, m;
void dfs(int u = 1, int p = -1, int x = 0)
{
    xr[u] = x;
    for (auto [v, w] : adj[u])
        if (v != p)
        {
            if (xr[v] == -1)
                dfs(v, u, x ^ w);
            else
                xb.add(x ^ w ^ xr[v]);
        }
}
void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    xr.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    xb.add(0);
    dfs();
    cout << xb.minxor(xr[n]) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

