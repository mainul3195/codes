#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << 2 * i + 1 << " ";
    cout << "\n";
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