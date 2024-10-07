#include <bits/stdc++.h>
using namespace std;
long long n;
long long okdone(long long l = 0, long long r = n - 1)
{
    if (l + 1 >= r)
        return 0;
    long long k = log2(r + .5);
    long long m = (1LL << k) - 1;
    return m * (m - 1) / 2 + (1LL << k) * (r - m - 1) + (m & r) + okdone(0, r - (1LL << k));
}
void solve()
{
    cin >> n;
    cout << okdone() << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}