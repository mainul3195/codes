#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    long long ans = 0;
    for (long long i = 1; (i <= b) && (i * i - i <= a); i++)
    {
        long long start = max(1LL, i * i - i);
        ans += (a - start) / (i * i) + 1;
        // cout << ans << " ";
    }
    cout << ans << "\n";
    // cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}