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
long long bigPow(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * bigPow(b, p - 1);
    long long t = bigPow(b, p / 2);
    return t * t;
}
vector<int> janina;
vector<pair<long long, int>> mul;
bool possible(long long x)
{
    for (auto [p, c] : mul)
    {
        long long tmp = x;
        long long cnt = 0;
        while (tmp > 1)
        {
            cnt += tmp / p;
            tmp /= p;
        }
        // cout << p << " " << c << " " << cnt << "\n";
        if (cnt < c)
            return 0;
    }
    return 1;
}
void solve()
{
    long long n;
    cin >> n;
    for (auto p : prime)
    {
        if (p * p > n)
            break;
        int cnt = 0;
        while (n % p == 0)
        {
            cnt++;
            n /= p;
        }
        if (cnt)
            mul.push_back({p, cnt});
    }
    if (n > 1)
        mul.push_back({n, 1});
    // for(auto [p, c]: mul)
    //     cout << p << " " << c << "\n";
    // cout << possible(250000000004ll);
    long long l = 2, r = 1000000000012LL, mid, ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // cout << mid << " -> " << possible(mid) << "\n";
        if (possible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    janina.push_back(0);
    janina.push_back(1);
    for (int i = 2; i < 100; i++)
        janina.push_back(janina.back() + i);
    // for (auto i : janina)
    //     cout << i << "\n";
    solve();
    return 0;
}