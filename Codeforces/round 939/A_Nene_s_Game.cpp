#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, q;
    cin >> k >> q;
    int mn = 1000000;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        mn = min(mn, x);
    }
    while (q--)
    {
        int n;
        cin >> n;
        cout << min(n, mn - 1) << " ";
    }
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