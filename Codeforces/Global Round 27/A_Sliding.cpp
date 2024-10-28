#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    cout << (long long)(n - r) * ((m - 1) + m) + m - c << "\n";
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