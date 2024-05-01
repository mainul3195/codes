#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    if (n < k)
    {
        cout << n << "\n";
        return;
    }
    for (auto [a, b] : mp)
    {
        if (b >= k)
        {
            cout << k - 1 << "\n";
            return;
        }
    }
    cout << n << "\n";
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