#include <bits/stdc++.h>
using namespace std;
#define Mod 998244353
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
void solve()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        sum += x;
    }
    sum %= Mod;
    for (long long k = 1; k <= n; k++)
        cout << (((k * sum) % Mod) * modInverse(2 * n)) % Mod << " \n"[k == n];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}