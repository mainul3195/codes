#include <bits/stdc++.h>
using namespace std;
long long bigMod(long long b, long long p, long long mod)
{
    if (!p)
        return 1;
    long long tmp = bigMod(b, p / 2, mod);
    tmp = tmp * tmp % mod;
    if (p & 1)
        tmp = tmp * b % mod;
    return tmp;
}
void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long pw = bigMod(b, c, 1000000006);
    cout << bigMod(a, pw, 1000000007) << "\n";
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