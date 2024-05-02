#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin >> x;
    int mx = -1, ans;
    for (int y = 1; y < x; y++)
    {
        int g = __gcd(x, y) + y;
        if (g > mx)
        {
            mx = g;
            ans = y;
        }
    }
    cout << ans << "\n";
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