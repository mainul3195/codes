#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n, -1);
    int x = 1;
    for (int i = k - 1; i < n; i += k)
        v[i] = x++;
    for (int i = 0; i < n; i++)
        if (v[i] == -1)
            v[i] = x++;
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
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