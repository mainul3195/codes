#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += n / (double)i;
    cout << fixed << setprecision(2) << ans << "\n";
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