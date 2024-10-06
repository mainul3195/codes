#include <bits/stdc++.h>
using namespace std;
#define int long long
long long okdone(long long u)
{
    if (!u)
        return u;
    return u & 1 ? okdone(u / 2) : u / 2;
}
void solve()
{
    int n;
    cin >> n;
    long long xr = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        xr ^= okdone(x);
    }
    if (xr)
        cout << "YES\n";
    else
        cout << "NO\n";

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