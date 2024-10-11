#include <bits/stdc++.h>
using namespace std;
#define eps 1e-15
void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    double mn = 1e14, mx = 0;
    for (auto &[a, b] : v)
        cin >> a >> b;
    // for(auto [a, b]: v)
    //     cout << a << " " << b << "\n";
    for (int i = 1; i <= n; i++)
    {
        mn = min(mn, (double)v[i - 1].second / i);
        mx = max(mx, (double)v[i - 1].first / i);
        // if(mx == 56)
        //     cout << i << " ...\n";
    }
    // cout << mn << ' ' << mx << " ";
    if (mx > mn)
        cout << "-1\n";
    else
        cout << fixed << setprecision(8) << 1 / mn << "\n";
    // int n;
    // cin >> n;
    // cout << n << "\n";
    return;
}
int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
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