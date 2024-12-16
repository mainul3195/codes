#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000009
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
    long long ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        ans = (ans * ((2 * x + 1) % Mod) % Mod);
    }
    ans = (ans - 1 + Mod) % Mod;
    ans = ans * modInverse(2) % Mod;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}