// Inspired from solution by NH Nayeem vai

#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int w[N], compressed[N];
vector<int> divisors[N];
void sieve()
{
    for (int i = 1; i < N; i++)
        compressed[i] = 1;
    for (int i = 2; i < N; i++)
    {
        bool prime = (w[i] == 0);
        for (int j = i; j < N; j += i)
            if (prime)
                w[j]++, compressed[j] *= i;
    }
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            if (compressed[j] == j)
                divisors[j].push_back(i);
    return;
}
int par[N], minw[N];
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
        par[i] = i, minw[i] = w[i];
    if (l == 1)
    {
        int ans = 0;
        for (int i = l + 1; i <= r; i++)
            ans += w[i];
        cout << ans << "\n";
        return;
    }
    if (r - l < 50)
    {
        vector<array<int, 3>> v;
        for (int i = l; i < r; i++)
            for (int j = i + 1; j <= r; j++)
            {
                int cost = w[i] + w[j] - w[__gcd(i, j)];
                v.push_back({cost, i, j});
            }
        sort(v.begin(), v.end());
        int ans = 0;
        for (auto [cost, a, b] : v)
        {
            int pa = getpar(a);
            int pb = getpar(b);
            if (pa != pb)
                par[pb] = pa, ans += cost;
        }
        cout << ans << "\n";
        return;
    }
    vector<array<int, 2>> nw;
    for (int i = l; i <= r; i++)
        nw.push_back({compressed[i], i});
    sort(nw.begin(), nw.end());
    vector<int> original(r + 1, -1);
    int ans = 0;
    for (auto [num, i] : nw)
    {
        for (auto div : divisors[num])
            if (original[div] != -1)
            {
                int u = original[div];
                int v = i;
                int pu = getpar(u);
                int pv = getpar(v);
                par[pv] = pu;
                ans += w[num];
                minw[pu] = min(minw[pu], minw[pv]);
                break;
            }
        original[num] = i;
    }
    for (int i = l; i <= r; i++)
        if (getpar(i) == i)
            ans += minw[i] + 1;
    cout << ans - 2 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}