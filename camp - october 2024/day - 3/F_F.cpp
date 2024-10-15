#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define lim 1000005
vector<vector<int>> divs(lim);
void find_divs()
{
    for (int i = 1; i < lim; i++)
        for (int j = i; j < lim; j += i)
            divs[j].push_back(i);
    return;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % mod;
}
long long modInverse(long long n)
{
    return bigMod(n, mod - 2);
}
vector<long long> div_sum(lim, 0), pair_sum(lim, 0);
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    find_divs();
    for (auto i : a)
        for (auto d : divs[i])
        {
            (pair_sum[d] += div_sum[d] * i) %= mod;
            (div_sum[d] += i) %= mod;
        }
    long long ans = 0;
    for (int i = lim - 1; i > 0; i--)
    {
        for (int j = 2 * i; j < lim; j += i)
            (pair_sum[i] -= pair_sum[j]) %= mod;
        (ans += pair_sum[i] * modInverse(i)) %= mod;
    }
    cout << (ans + mod) % mod << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}