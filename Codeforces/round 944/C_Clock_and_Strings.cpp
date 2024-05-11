#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    if (a < c)
    {
        if (c < b && d > b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        if (a < d && b > d)
            cout << "YES\n";
        else
            cout << "NO\n";
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