#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n), nw;
    for (auto &[a, b] : v)
        cin >> a;
    for (auto &[a, b] : v)
        cin >> b;
    int mx_ans = -1000000000;
    for (int i = 0; i < n; i++)
    {
        int ans = v[i].first + v[i].second;
        for (int j = 0; j < n; j++)
            if (i != j)
                ans += max(v[j].first, v[j].second);
        mx_ans = max(mx_ans, ans);
    }
    cout << mx_ans << "\n";
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