#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
void solve()
{
    long long w, g, l;
    cin >> w >> g >> l;
    w%=mod;
    g%=mod;
    l%=mod;
    cout << (2*l+1)%mod*((w-g+mod)%mod)%mod << "\n";
    return;
}
int32_t main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}