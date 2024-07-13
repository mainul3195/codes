#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, y, k;
    cin >> x >> y >> k;
    long long nxt = (x / y + 1) * y;
    while (1)
    {
        if (nxt - x > k)
        {
            cout << x + k << "\n";
            return;
        }
        k -= (nxt - x);
        while (nxt % y == 0)
            nxt /= y;
        x = nxt;
        nxt = (x + y - 1) / y * y;
        if (x == 1)
        {
            k %= (nxt - x);
            cout << k + 1 << "\n";
            return;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        // cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}