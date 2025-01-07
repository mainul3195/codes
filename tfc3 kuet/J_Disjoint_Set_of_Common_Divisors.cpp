#include <bits/stdc++.h>
using namespace std;
#define lim 10000000
#define ckbit(x) (fLd[(x) / 64] & (1 << ((x) % 64) / 2))
#define cngbit(x) (fLd[(x) / 64] |= (1 << ((x) % 64) / 2))
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
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    int cnt = 0;
    for (auto p : prime)
    {
        if (p * p > g)
            break;
        if (g % p == 0)
        {
            cnt++;
            while (g % p == 0)
                g /= p;
        }
    }
    if (g > 1)
        cnt++;
    cout << cnt + 1 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}