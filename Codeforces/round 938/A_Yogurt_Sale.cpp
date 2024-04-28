#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << (n / 2 * min(b, 2 * a) + (n % 2) * a) << "\n";
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