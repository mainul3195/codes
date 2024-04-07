#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = {x, i};
    }
    int need = (k + m - 1) / m;
    sort(v.begin(), v.end());
    vector<pair<int, int>> only_needed;
    for (int i = 0; i < need; i++)
        only_needed.push_back({v[i].second, v[i].first});
    sort(only_needed.begin(), only_needed.end());
    vector<long long> val;
    val.push_back(0);
    for (auto [a, b] : only_needed)
        val.push_back(b);
    // for (int i = 1; i < val.size(); i++)
    //     cout << val[i] << " \n"[i == val.size() - 1];
    long long extra = 0;
    if (k % m)
        extra = m - k % m;
    int sz = val.size();
    long long ans = 0, prev_taken = 0;
    for (int i = 1; i < sz; i++)
    {
        ans += (val[i] + prev_taken) * m;
        prev_taken += m;
    }
    // cout << ans << "\n";
    long long minus = 0;
    prev_taken = 0;
    for (int i = 1; i < sz; i++)
    {
        long long cur_price = val[i] + prev_taken;
        minus = max(minus, cur_price * extra + extra * (sz - i - 1) * m);
        prev_taken += m;
    }
    cout << ans - minus << "\n";
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