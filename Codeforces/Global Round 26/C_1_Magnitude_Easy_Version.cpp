#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
vector<vector<long long>> dp;
long long okdone(int i, int t)
{
    if (i == -1)
        return 0;
    long long &ret = dp[i][t];
    if (~ret)
        return ret;
    if (t == 0)
        ret = min({okdone(i - 1, 0) + v[i], abs(okdone(i - 1, 0) + v[i]), okdone(i - 1, 1) + v[i], abs(okdone(i - 1, 1) + v[i])});
    else
        ret = max({okdone(i - 1, 0) + v[i], abs(okdone(i - 1, 0) + v[i]), okdone(i - 1, 1) + v[i], abs(okdone(i - 1, 1) + v[i])});
    return ret;
}
void solve()
{
    cin >> n;
    v = vector<long long>(n);
    dp = vector<vector<long long>>(n + 2, vector<long long>(2, -1));
    for (auto &i : v)
        cin >> i;
    cout << okdone(n - 1, 1) << "\n";
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