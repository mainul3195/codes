#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        while (j < m && (b[j] != a[i]))
            j++;
        if (j < m)
            i++, j++;
    }
    cout << i << "\n";
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