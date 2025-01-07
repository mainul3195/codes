#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<vector<int>>(2 * n);
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << j << " ";
        cout << "\n";
    }
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