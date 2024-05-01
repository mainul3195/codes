#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> v;
vector<vector<long long>> dp;
long long okdone(int i, int rem)
{
    if (i >= n)
        return 0;
    if (~dp[i][rem])
        return dp[i][rem];
    long long mx = okdone(i + 1, rem);
    for (int take = 1; (take <= rem) && (i + take <= n); take++)
    {
        long long mn_val = 2000000000;
        for (int j = i; j - i < take; j++)
            mn_val = min(mn_val, v[j]);
        if (i)
            mn_val = min(mn_val, v[i - 1]);
        if (i + take < n)
            mn_val = min(mn_val, v[i + take]);
        long long tmp = 0;
        for (int j = i; j - i < take; j++)
            tmp += v[j] - mn_val;
        // cout << "(" << i << ":" << rem << ") -> " << take << " " << mn_val << " " << tmp << "\n";
        mx = max(mx, tmp + okdone(i + take + 1, rem - take));
    }
    return dp[i][rem] = mx;
}
void solve()
{
    cin >> n >> k;
    dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1));
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    long long sum = 0;
    for (auto i : v)
        sum += i;
    long long minant = okdone(0, k);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "From " << i << ": ";
    //     for (int j = 0; j <= k; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << sum - minant << "\n";
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