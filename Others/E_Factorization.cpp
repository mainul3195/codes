#include <bits/stdc++.h>
using namespace std;
#define ckbit(x) (fLd[(x) / 64] & (1 << ((x) % 64) / 2))
#define cngbit(x) (fLd[(x) / 64] |= (1 << ((x) % 64) / 2))
#define max_lim 1000000
#define lim 1000000
#define Mod 1000000007
vector<long long> f(max_lim + 1);
void precalc()
{
    f[0] = 1;
    for (long long i = 1; i <= max_lim; i++)
        f[i] = f[i - 1] * i % Mod;
    return;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod - 2);
}
long long nCr(long long n, long long r)
{
    return (((f[n] * modInverse(f[r])) % Mod) * modInverse(f[n - r])) % Mod;
}

int fLd[lim / 64 + 2];
vector<long long> prime;
void sieve()
{
    prime.push_back(2);
    for (long long i = 3; i * i <= lim; i += 2)
        if (!ckbit(i))
            for (long long j = i * i; j <= lim; j += 2 * i)
                cngbit(j);
    for (long long i = 3; i <= lim; i += 2)
        if (!ckbit(i))
            prime.push_back(i);
    return;
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    long long ans = 1;
    for (auto p : prime)
    {
        if (p * p > m)
            break;
        int cnt = 0;
        while (m % p == 0)
            cnt++, m /= p;
        ans = ans * nCr(cnt + n - 1, n - 1) % Mod;
    }
    if (m != 1)
        ans = ans * nCr(n, n - 1) % Mod;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    sieve();
    solve();
    return 0;
}