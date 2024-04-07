#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long x, y;
    cin >> x >> y;
    long long mx = max(x, y);
    long long upper = mx * mx;
    long long lower = (mx - 1) * (mx - 1);
    if (y > x)
    {
        if (mx % 2)
            cout << upper - x + 1 << "\n";
        else
            cout << lower + x << "\n";
    }
    else
    {
        if (mx % 2)
            cout << lower + y << "\n";
        else
            cout << upper - y + 1 << "\n";
    }
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