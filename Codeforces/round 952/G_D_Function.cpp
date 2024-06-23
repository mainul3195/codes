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
void solve()
{
    long long l, r, k;
    cin >> l >> r >> k;
    if (k >= 10)
        cout << "0\n";
    else
    {
        long long d = 9 / k + 1;
        cout << (bigMod(d, r) - bigMod(d, l) + Mod) % Mod << "\n";
    }
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