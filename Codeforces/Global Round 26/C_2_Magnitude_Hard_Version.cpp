#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n;
vector<long long> v;
vector<vector<long long>> dp, path;
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
long long find_path(int i, int t)
{
    if (i == 0)
    {
        if (v[i] < 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    long long &ret = path[i][t];
    if (~ret)
        return ret;
    ret = 0;
    long long ans = okdone(i, t);
    long long val1 = okdone(i - 1, 1) + v[i];
    long long val2 = abs(okdone(i - 1, 1) + v[i]);
    long long val3 = okdone(i - 1, 0) + v[i];
    long long val4 = abs(okdone(i - 1, 0) + v[i]);
    if (ans == val1)
        ret = (ret + find_path(i - 1, 1)) % mod;
    if (ans == val2)
        ret = (ret + find_path(i - 1, 1)) % mod;
    if (okdone(i - 1, 1) != okdone(i - 1, 0))
    {
        if (ans == val3)
            ret = (ret + find_path(i - 1, 0)) % mod;
        if (ans == val4)
            ret = (ret + find_path(i - 1, 0)) % mod;
    }
    return ret;
}
void solve()
{
    cin >> n;
    v = vector<long long>(n);
    dp = path = vector<vector<long long>>(n + 2, vector<long long>(2, -1));
    for (auto &i : v)
        cin >> i;
    long long tot = find_path(n - 1, 1) % mod;
    // cout << okdone(n - 1, 1) << "\n";
    cout << tot << "\n";
    // cout << find_path(0, 0) << "\n";
    // cout << find_path(0, 1) << "\n";
    // cout << "\n";
    // cout << find_path(1, 0) << "\n";
    // cout << find_path(1, 1) << "\n";
    // cout << "\n";
    // cout << find_path(2, 0) << "\n";
    // cout << find_path(2, 1) << "\n";
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