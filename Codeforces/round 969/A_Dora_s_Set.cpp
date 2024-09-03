#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    if (!(l & 1))
        l++;
    if (!(r & 1))
        r--;
    r++;
    cout << (r - l + 1) / 2 / 2 << "\n";
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