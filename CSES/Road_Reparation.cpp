#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> par, child;
vector<tuple<int, int, long long>> edge;
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
bool cmp(tuple<int, int, long long> &a, tuple<int, int, long long> &b)
{
    auto [au, av, aw] = a;
    auto [bu, bv, bw] = b;
    return aw < bw;
}
void solve()
{
    cin >> n >> m;
    par = vector<int>(n + 1);
    child = vector<int>(n + 1, 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end(), cmp);
    long long tot = 0;
    int mx_connected = 1;
    for (auto [u, v, w] : edge)
    {
        int pu = getpar(u);
        int pv = getpar(v);
        if (pu != pv)
        {
            tot += w;
            if (child[pu] > child[pv])
            {
                par[pv] = pu;
                child[pu] += child[pv];
                child[pv] = 0;
                mx_connected = max(mx_connected, child[pu]);
            }
            else
            {
                par[pu] = pv;
                child[pv] += child[pu];
                child[pu] = 0;
                mx_connected = max(mx_connected, child[pv]);
            }
        }
    }
    if (mx_connected != n)
        cout << "IMPOSSIBLE\n";
    else
        cout << tot << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}