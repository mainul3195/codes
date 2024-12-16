#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long l, r;
    cin >> l >> r;
    cout << ((r / 3) - ((l - 1) / 3)) << "\n";
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