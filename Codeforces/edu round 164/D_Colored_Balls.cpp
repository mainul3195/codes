#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n;
vector<int> v;
vector<vector<long long>> dp;
long long okdone(int i = 0, int sum = 0)
{
    if (i == n)
        return 0;
    long long &ret = dp[i][sum];
    if (~ret)
        return ret;
    ret = 0;
    if (sum <= v[i])
        (ret += v[i]) %= mod;
    else
        (ret += (sum + v[i] + 1) / 2) %= mod;
    (ret += okdone(i + 1, sum)) %= mod;
    (ret += okdone(i + 1, sum + v[i])) %= mod;
    return dp[i][sum] = ret;
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    int sum = 0;
    for (auto &i : v)
    {
        cin >> i;
        sum += i;
    }
    dp = vector<vector<long long>>(n + 2, vector<long long>(sum + 2, -1));
    sort(v.begin(), v.end());
    cout << okdone() << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}