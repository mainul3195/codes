#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    long long tmp = bigMod(b, p / 2);
    tmp = tmp * tmp % mod;
    if (p & 1)
        tmp = tmp * b % mod;
    return tmp;
}
void solve()
{
    long long a, b;
    cin >> a >> b;
    cout << bigMod(a % mod, b) << "\n";
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