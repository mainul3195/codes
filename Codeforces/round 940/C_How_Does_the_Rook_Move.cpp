#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long ans[300005];
void solve()
{
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        n--;
        if (l != r)
            n--;
    }
    cout << ans[n] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    ans[3] = 7;
    for (int i = 4; i < 300005; i++)
        ans[i] = (ans[i - 1] + 2 * (i - 1) % mod * ans[i - 2] % mod) % mod;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}