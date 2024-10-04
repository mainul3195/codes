#include <bits/stdc++.h>
using namespace std;

void solve()
{
    double ab, ac, bc, r;
    cin >> ab >> ac >> bc >> r;
    cout << fixed << setprecision(10) << sqrt(ab * ab * (r / (r + 1))) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}