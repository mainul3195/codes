#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int mid_ind = (n - 1) / 2;
    int target = v[mid_ind] + 1;
    int ans = 0;
    for (int i = mid_ind; i < n && v[i] < target; i++)
        ans += target - v[i];
    cout << ans << "\n";
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