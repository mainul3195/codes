#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> par, child;
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
void solve()
{
    cin >> n >> m;
    par = vector<int>(n + 1);
    child = vector<int>(n + 1, 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    long long tot = 0;
    int mx_connected = 1, tot_componenet = n;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        int pu = getpar(u);
        int pv = getpar(v);
        if (pu != pv)
        {
            tot_componenet--;
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
        cout << tot_componenet << " " << mx_connected << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}