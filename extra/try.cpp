#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (__builtin_popcount(n) == 1)
        cout << "-1\n";
    else
    {
        int a = (1 << (int)(log2(n + .5)));
        cout << a << " " << n - a << "\n";
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