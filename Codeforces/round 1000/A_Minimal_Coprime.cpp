#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = r - l;
    if (ans == 0 && r == 1)
        ans++;
    cout << ans << "\n";
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