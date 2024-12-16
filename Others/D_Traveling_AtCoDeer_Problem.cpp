#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mn = 100000000, mx = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << mx - mn << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}