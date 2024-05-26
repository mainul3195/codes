#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m > n)
        cout << "No\n";
    else
    {
        if ((n % 2) == (m % 2))
            cout << "Yes\n";
        else
            cout << "No\n";
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