#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    // for two
    for (int i = 1; i <= n; i++)
        if (v[v[i]] == i)
        {
            cout << "2\n";
            return;
        }
    cout << "3\n";
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