#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << 5000 << " ";
    int prev = 5000;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        prev += x;
        cout << prev << " ";
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