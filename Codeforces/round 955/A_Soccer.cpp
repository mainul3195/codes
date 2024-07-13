#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a < b && c > d) || (b < a && d > c))
        cout << "NO\n";
    else
        cout << "YES\n";
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