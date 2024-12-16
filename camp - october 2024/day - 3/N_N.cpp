#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long n, m;
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

long long rangeSum(long long l, long long r)
{
    return (((r % mod) * ((r + 1) % mod) % mod) - ((l % mod) * ((l - 1) % mod) % mod) + mod) % mod * modInverse(2) % mod;
}

void solve()
{
    cin >> n >> m;
    long long tot = (n % mod) * (m % mod) % mod;
    m = min(n, m);
    long long biyog = 0;
    long long last;
    for (long long i = 1; i * i <= n && i <= m; i++)
        (biyog += ((n / i) * i) % mod) %= mod, last = n / i;
    for (long long i = 1; i * i <= n && i <= m && i < last; i++)
    {
        long long l = n / (i + 1) + 1, r = n / i;
        r = min(r, m);
        if (r >= l)
            (biyog += (rangeSum(l, r) * i % mod)) %= mod;
    }
    cout << (tot - biyog + mod) % mod << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tot = 0;

    solve();
    return 0;
}