#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long mx = v.back();
    long long lc = 1;
    for (auto i : v)
    {
        lc = lcm(lc, i);
        if (lc > mx)
        {
            cout << n << "\n";
            return;
        }
    }
    vector<long long> div;
    for (long long i = 1; i * i <= mx; i++)
        if (mx % i == 0)
        {
            div.push_back(i);
            div.push_back(mx / i);
        }
    sort(div.begin(), div.end());
    int ans = 0;
    for (auto d : div)
    {
        auto it = lower_bound(v.begin(), v.end(), d);
        if (it != v.end() && *it == d)
            continue;
        int cnt = 0;
        long long l = 1;
        for (auto i : v)
            if (d % i == 0)
            {
                cnt++;
                l = lcm(l, i);
            }
        if (l == d)
            ans = max(ans, cnt);
    }
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