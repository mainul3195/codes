#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
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
long long ncr(long long n, long long r)
{
    long long ans = 1;
    long long tmp = n;
    for (int i = 0; i < r; i++)
    {
        ans = ans * tmp % Mod;
        tmp--;
    }
    long long div = 1;
    for (long long i = 1; i <= r; i++)
        div = div * i % Mod;
    ans = ans * modInverse(div) % Mod;
    return ans;
}
void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = bigMod(2, n) - 1;
    ans = (ans + Mod) % Mod;
    ans = (ans - ncr(n, a) + Mod) % Mod;
    ans = (ans - ncr(n, b) + Mod) % Mod;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}